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


#include "stm32f103x6_TIMER_2to5_driver.h"
#include "stm32f103x6.h"

void led_toggling();


int main(void)
{
	// creating a periodic timer for 2 seconds
	uint32_t time = 2000;
	TIM2_5_config TIM2_config;
	TIM2_config.TIMER_Auto_Reload_preload_EN = TIMER_Auto_Reload_preload_Enable;
	TIM2_config.TIMER_Count_Direction = TIMER_Down_Counter;
	TIM2_config.TIMER_Mode = TIMER_Edge_aligned_Mode;
	TIM2_config.TIMER_operation_mode = TIMER_Periodic_Mode_Enable;
	TIM2_config.TIMER_Update_REQ_Source = TIMER_MUTI_Update_Request_Sources;
	TIM2_config.TIMER_Update_EN = TIMER_Update_Enable;
	TIM2_config.TIMER_Update_IRQ_EN = TIMER_Update_IRQ_Enable;
	TIM2_config.P_IRQ_Callback = led_toggling;

	MCAL_Timer_init(TIM2, &TIM2_config);
	MCAL_Timer_Start(TIM2, time);

	while(1)
	{

	}
}

void led_toggling()
{
	MCAL_GPIO_Toggle_Pin(GPIOB, GPIO_PIN_13);
}

