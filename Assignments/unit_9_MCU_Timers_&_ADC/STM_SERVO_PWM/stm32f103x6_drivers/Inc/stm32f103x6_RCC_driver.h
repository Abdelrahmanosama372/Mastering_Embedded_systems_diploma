/*
 * stm32f103x6_RCC_driver.h
 *
 *
 *      Author: Abdelrahman osama
 */

// Partial implementation of RCC driver
// assumed that HSI is the running clock

#ifndef INC_STM32F103X6_RCC_DRIVER_H_
#define INC_STM32F103X6_RCC_DRIVER_H_
#include "stm32f103x6.h"


#define RCC_HSI_clock       (uint32_t)(1 << 0)  //HSION: Internal high-speed clock enable

//=====================================================================================
//									APIs Prototypes
//=====================================================================================

uint32_t MCAL_RCC_get_SYSCLK(RCC_TypeDef *_RCC);
uint32_t MCAL_RCC_get_HCLK(RCC_TypeDef *_RCC);
uint32_t MCAL_RCC_get_PCLK1(RCC_TypeDef *_RCC);
uint32_t MCAL_RCC_get_PCLK2(RCC_TypeDef *_RCC);

#endif /* INC_STM32F103X6_RCC_DRIVER_H_ */
