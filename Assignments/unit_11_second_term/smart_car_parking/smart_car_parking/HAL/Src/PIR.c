/*
 * PIR.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Abdelrahman
 */

#include "PIR.h"

void PIR_init(GPIO_TypeDef *GPIOx, uint16_t PIR_pin)
{
	GPIO_Pin_Config pin_config;
	pin_config.Pin_Mode = Input_Pull_Down;
	pin_config.Pin_Number = PIR_pin;
	MCAL_GPIO_Init(GPIOx, &pin_config);
}

uint8_t PIR_is_Car_Detected(GPIO_TypeDef *GPIOx, uint16_t PIR_pin)
{
	return MCAL_GPIO_Read_Pin(GPIOx, PIR_pin) == GPIO_PIN_SET;
}
