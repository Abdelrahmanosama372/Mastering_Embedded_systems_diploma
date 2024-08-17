/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman osama
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6_gpio_driver.h"
#include "stm32f103x6_EXTI_driver.h"
#include "stm32f103x6.h"


extern int _estack;

#define TASKA_STACK_SIZE 100
#define TASKB_STACK_SIZE 100

unsigned int _S_MSP = &_estack;
unsigned int _E_MSP;

unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;

unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;


#define OS_ADD_TO_PSP(add)  __asm("MOV R0, %0 \t\n MSR PSP, R0": : "r"(add))

#define OS_SWITCH_SP_TO_PSP __asm("MRS R0, CONTROL \t\n ORR R0, #0x2 \t\n MSR CONTROL, R0");
#define OS_SWITCH_SP_TO_MSP __asm("MRS R0, CONTROL \t\n AND R0, #0x5 \t\n MSR CONTROL, R0");

#define Switch_To_UnPrivillageMode __asm("NOP \t\n \
										  MRS r3, CONTROL \t\n \
										  ORR r3, 0x1 \t\n \
										  MSR CONTROL, r3")

#define Switch_To_PrivillageMode __asm("NOP \t\n \
										MRS r3, CONTROL \t\n \
										LSR r3, 0x1 \t\n \
										LSL r3, 0x1 \t\n \
										MSR CONTROL, r3")


#define OS_GENERATE_EXCEPTION    __asm("SVC #0x3");

void wait();
void ledtoggling();

int taskA(int a, int b)
{
	return a + b;
}

int taskB(int a, int b)
{
	return a - b;
}

int task_flag = 0;

void OS_start();


void SVC_Handler()
{
	Switch_To_PrivillageMode;
}

int main(void)
{

	NVIC_IRQ23_EXTI5_9_ENABLE;

	RCC_GPIOA_ENABLE();
	RCC_GPIOB_ENABLE();
	RCC_AFIO_ENABLE();

	GPIO_Pin_Config conigPin;

	conigPin.Pin_Mode = General_Purpose_Output_PP;
	conigPin.Pin_Number = GPIO_PIN_13;
	conigPin.Pin_Speed = GPIO_Pin_Max_Speed10M;
	MCAL_GPIO_Init(GPIOB, &conigPin);

	EXTI_pinConfig_t EXTI_pin;
	EXTI_pin.EXTI_GPIO_pin = EXTI9PB9;
	EXTI_pin.trigger_case = EXTI_RISING_Trigger;
	EXTI_pin.P_IRQ_callback = ledtoggling;
	EXTI_pin.IR_EN = EXTI_IRQ_ENABLE;
	MCAL_EXTI_GPIO_Init(&EXTI_pin);

	OS_start();

	while(1)
	{

	}
}

void ledtoggling()
{
	MCAL_GPIO_Toggle_Pin(GPIOB, GPIO_PIN_13);
	if(task_flag == 0){
		task_flag = 1;
	}else {
		task_flag = 0;
	}
}


void OS_start()
{
	_E_MSP = _S_MSP - 512;

	_S_PSP_TA = _E_MSP - 4;
	_E_PSP_TA = _S_PSP_TA - TASKA_STACK_SIZE;

	_S_PSP_TB = _E_PSP_TA - 4;
	_E_PSP_TB = _S_PSP_TB - TASKB_STACK_SIZE;

	while(1)
	{
		if(task_flag == 0) // add
		{
			// add task A psp
			OS_ADD_TO_PSP(_S_PSP_TA);

			// switch sp to PSP
			OS_SWITCH_SP_TO_PSP;

			// switch to unprivillage Mode
			Switch_To_UnPrivillageMode;

			taskA(2,3);

			// generate exception to switch to privillage mode
			OS_GENERATE_EXCEPTION;

			// switch SP to MSP
			OS_SWITCH_SP_TO_MSP;

		}
		else  // subtract
		{
			// add task B psp
			OS_ADD_TO_PSP(_S_PSP_TB);

			// switch sp to PSP
			OS_SWITCH_SP_TO_PSP;

			// switch to unprivillage Mode
			Switch_To_UnPrivillageMode;

			taskB(3,2);

			// generate exception to switch to privillage mode
			OS_GENERATE_EXCEPTION;

			// switch SP to MSP
			OS_SWITCH_SP_TO_MSP;
		}
	}

}
