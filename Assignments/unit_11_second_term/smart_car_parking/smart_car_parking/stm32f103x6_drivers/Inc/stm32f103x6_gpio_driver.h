/*
 * stm32f103x6_gpio_driver.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Abdelrahman osama
 */

#ifndef INC_STM32F103X6_GPIO_DRIVER_H_
#define INC_STM32F103X6_GPIO_DRIVER_H_

#include "stm32f103x6.h"

typedef struct
{
	uint16_t Pin_Mode;      // indicate mode of pin @ref pin modes
	uint16_t Pin_Number;    // indicate pin number @ref pin numbers
	uint8_t Pin_Speed;      // indicate  Output mode, max speed of pin @ref pin max speeds

}GPIO_Pin_Config;


// pin modes

#define Analog_Mode                                      0x00000000u
#define Floating_Input                                   0x00000001u   // reset state
#define Input_Pull_Up                                    0x00000002u
#define Input_Pull_Down                                  0x00000003u
#define General_Purpose_Output_PP                        0x00000004u
#define General_Purpose_Output_OD                        0x00000005u
#define Alternate_Function_Output_PP                     0x00000006u
#define Alternate_Function_Output_OD                     0x00000007u


// pin max speeds

#define GPIO_Pin_Max_Speed10M     0x00000001u
#define GPIO_Pin_Max_Speed2M	  0x00000002u
#define GPIO_Pin_Max_speed50M     0x00000003u

// pin numbers

#define GPIO_PIN_0               0x00000001UL
#define GPIO_PIN_1               0x00000002UL
#define GPIO_PIN_2				 0x00000004UL
#define GPIO_PIN_3               0x00000008UL
#define GPIO_PIN_4               0x00000010UL
#define GPIO_PIN_5               0x00000020UL
#define GPIO_PIN_6               0x00000040UL
#define GPIO_PIN_7               0x00000080UL
#define GPIO_PIN_8               0x00000100UL
#define GPIO_PIN_9               0x00000200UL
#define GPIO_PIN_10              0x00000400UL
#define GPIO_PIN_11              0x00000800UL
#define GPIO_PIN_12              0x00001000UL
#define GPIO_PIN_13              0x00002000UL
#define GPIO_PIN_14              0x00004000UL
#define GPIO_PIN_15              0x00008000UL

// pin status

#define GPIO_PIN_RESET            0
#define GPIO_PIN_SET              1

// pin locking state

#define PIN_LOCK_NOT_ENABLED      0
#define PIN_LOCK_ENABLED          1



void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_Pin_Config *config_pin);
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx);
uint8_t MCAL_GPIO_Read_Pin(GPIO_TypeDef * GPIOx , uint16_t pinnumber );
uint16_t MCAL_GPIO_Read_Port(GPIO_TypeDef * GPIOx);
void MCAL_GPIO_Write_Pin(GPIO_TypeDef * GPIOx ,  uint16_t pinnumber , uint8_t value);
void MCAL_GPIO_Write_Port(GPIO_TypeDef * GPIOx  , uint16_t value);
void MCAL_GPIO_Toggle_Pin(GPIO_TypeDef * GPIOx , uint16_t pinnumber);
uint8_t MCAL_GPIO_Lock_Pin(GPIO_TypeDef * GPIOx , uint16_t pinnumber);



#endif /* INC_STM32F103X6_GPIO_DRIVER_H_ */
