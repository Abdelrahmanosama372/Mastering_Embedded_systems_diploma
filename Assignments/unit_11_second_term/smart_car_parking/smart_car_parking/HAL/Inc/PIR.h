/*
 * PIR.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Abdelrahman
 */

#ifndef INC_PIR_H_
#define INC_PIR_H_


#include "stm32f103x6_gpio_driver.h"

void PIR_init(GPIO_TypeDef *GPIOx, uint16_t PIR_pin);
uint8_t PIR_is_Car_Detected(GPIO_TypeDef *GPIOx, uint16_t PIR_pin);

#endif /* INC_PIR_H_ */
