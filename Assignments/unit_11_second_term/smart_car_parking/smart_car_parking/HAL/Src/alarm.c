/*
 * alarm.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Abdelrahman
 */

#include "alarm.h"
#include "Timer.h"

void alarm_toggle(GPIO_TypeDef *GPIOx, uint16_t alarm_pin);

void alarm_init(GPIO_TypeDef *GPIOx, uint16_t alarm_pin)
{
	GPIO_Pin_Config pin_config;
	pin_config.Pin_Mode = General_Purpose_Output_PP;
	pin_config.Pin_Number = alarm_pin;
	pin_config.Pin_Speed = GPIO_Pin_Max_Speed2M;
	MCAL_GPIO_Init(GPIOx, &pin_config);
	MCAL_GPIO_Write_Pin(GPIOx, alarm_pin, GPIO_PIN_SET);
}

void alarm_start(GPIO_TypeDef *GPIOx, uint16_t alarm_pin)
{
	alarm_toggle(GPIOx, alarm_pin);
	alarm_toggle(GPIOx, alarm_pin);
}

void alarm_toggle(GPIO_TypeDef *GPIOx, uint16_t alarm_pin)
{
	MCAL_GPIO_Write_Pin(GPIOx, alarm_pin, GPIO_PIN_RESET);
	dms(100);
	MCAL_GPIO_Write_Pin(GPIOx, alarm_pin, GPIO_PIN_SET);
	dms(100);
}

