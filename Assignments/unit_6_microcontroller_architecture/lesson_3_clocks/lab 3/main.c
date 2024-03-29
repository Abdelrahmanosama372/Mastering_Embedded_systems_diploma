/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include <stdint.h>

#define RCC_BASE        0x40021000
#define PORTA_BASE      0x40010800

#define RCC_CFGR        *((volatile uint32_t *) (RCC_BASE + 0x04))
#define RCC_CR          *((volatile uint32_t *) (RCC_BASE + 0x00))
#define RCC_APB2ENR     *((volatile uint32_t *) (RCC_BASE + 0x18))
#define GPIOA_CRH       *((volatile uint32_t *) (PORTA_BASE + 0x04))
#define GPIOA_ODR       *((volatile uint32_t *) (PORTA_BASE + 0x0c))

int main(void)
{
	//	Bits 21:18 PLLMUL: PLL multiplication factor
	//	0110: PLL input clock x 8

	RCC_CFGR |= 0b0110<<18;

	//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB low-speed clock
	//	(PCLK1).
	//	100: HCLK divided by 2

	RCC_CFGR |= 0b100<<8;

	//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB high-speed clock
	//	(PCLK2).
	//	101: HCLK divided by 4
	
	RCC_CFGR |= 0b101<<11;

	//	PLLON: PLL enable
	//	Set and cleared by software to enable PLL.
	//	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	//	PLL clock is used as system clock or is selected to become the system clock.
	//	0: PLL OFF
	//	1: PLL ON
	RCC_CR |= 0b1<<24;

	
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	// for loop counter
	while(1)
	{
		GPIOA_ODR |= 1<<13;         // set bit 13
		for(int i =0; i <5000; i++);
		GPIOA_ODR &= ~(1<<13);      // clear bit 13
		for(int i =0; i <5000; i++);
	}

}
