/*
 * alarm.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_ALARM_H_
#define INC_ALARM_H_

#include "stm32f103x6_gpio_driver.h"

void alarm_init(GPIO_TypeDef *GPIOx, uint16_t alarm_pin);
void alarm_start(GPIO_TypeDef *GPIOx, uint16_t alarm_pin);

#endif /* INC_ALARM_H_ */
