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


void wait();
void ledtoggling();

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

	__asm("nop \t\n nop\t\n");

	while(1)
	{

	}
}

void ledtoggling()
{
	MCAL_GPIO_Toggle_Pin(GPIOB, GPIO_PIN_13);
}
