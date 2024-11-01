/*
 * keyPad.h
 *
 * Created: 3/20/2024 2:28:45 PM
 *  Author: Abdelrahman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f103x6_gpio_driver.h"

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7

#define ALL_PINS (C0 | C1 | C2)

#define KEYPAD_PORT  GPIOB

void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */
