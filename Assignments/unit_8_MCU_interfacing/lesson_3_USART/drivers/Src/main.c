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

#include "stm32f103x6_USART_driver.h"
#include "stm32f103x6.h"








int main(void)
{
	uint16_t data;
	USART_config UART_config;
	UART_config.Baud_Rate = USART_Baude_Rate_115200;
	UART_config.Data_Length  = USART_Frame_Length_8;
	UART_config.HW_FlowControl = USART_HW_FC_disable;
	UART_config.Interrupt_Enable = USART_Interrupt_disable;
	UART_config.Parity = USART_Frame_parity_DISABLE;
	UART_config.Stop_Bits = USART_Frame_StopBit_one;
	UART_config.USART_MODE = USART_MODE_RX_TX;
	UART_config.p_callback = NULL;

	MCAL_USART_Init(USART1, &UART_config);
	MCAL_USART_GPIO_Set_Pins(USART1);

	while(1)
	{
		// receive data
		MCAL_USART_RX(USART1, &data, 1, Polling);
		// send the received data
		MCAL_USART_TX(USART1, &data, 1, Polling);


	}
}


