/*
 * stm32f103x6_EXTI_driver.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Abdelrahman osama
 */

#ifndef INC_STM32F103X6_EXTI_DRIVER_H_
#define INC_STM32F103X6_EXTI_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103x6_gpio_driver.h"

typedef struct
{
	GPIO_TypeDef *port;
	uint8_t Pin_number;
	uint8_t EXTI_InputLineNumber;
	uint8_t NVIC_IRQ_number;
}EXTI_GPIO_Mapping_t;

typedef struct
{

	EXTI_GPIO_Mapping_t EXTI_GPIO_pin;       // configure the gpio pin for specfic port and EXTI
											// this parameter must be set based on @ref EXTI_define

	uint8_t trigger_case;				    // specifies Rising or falling or both
											// this parameter is set based on @ref EXTI_trigger_define
	uint8_t IR_EN;							// this parameter must be set based on @ref EXTI_IR_state
	void (*P_IRQ_callback) (void);

}EXTI_pinConfig_t;

/*
 *====================================================================
 *					Macros configuration References
 *====================================================================
 */

//EXTI_trigger_cases
#define EXTI_RISING_Trigger               0
#define EXTI_FALLING_Trigger              1
#define EXTI_RisingAndFalling_trigger     2

//EXTI_IR_state
#define EXTI_IRQ_ENABLE         1
#define EXTI_IRQ_DISABLE        0

#define EXTI0               0
#define EXTI1               1
#define EXTI2               2
#define EXTI3               3
#define EXTI4               4
#define EXTI5               5
#define EXTI6               6
#define EXTI7               7
#define EXTI8               8
#define EXTI9               9
#define EXTI10              10
#define EXTI11              11
#define EXTI12              12
#define EXTI13              13
#define EXTI14              14
#define EXTI15              15

//EXTI_define
//
//EXTI0
#define EXTI0PA0                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_0,EXTI0,EXTI0_IRQ}
#define EXTI0PB0                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_0,EXTI0,EXTI0_IRQ}
#define EXTI0PC0                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_0,EXTI0,EXTI0_IRQ}
#define EXTI0PD0                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_0,EXTI0,EXTI0_IRQ}


//EXTI1
#define EXTI1PA1                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_1,EXTI1,EXTI1_IRQ}
#define EXTI1PB1                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_1,EXTI1,EXTI1_IRQ}
#define EXTI1PC1                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_1,EXTI1,EXTI1_IRQ}
#define EXTI1PD1                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_1,EXTI1,EXTI1_IRQ}


//EXTI2
#define EXTI2PA2                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_2,EXTI2,EXTI2_IRQ}
#define EXTI2PB2                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_2,EXTI2,EXTI2_IRQ}
#define EXTI2PC2                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_2,EXTI2,EXTI2_IRQ}
#define EXTI2PD2                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_2,EXTI2,EXTI2_IRQ}


//EXTI3
#define EXTI3PA3                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_3,EXTI3,EXTI3_IRQ}
#define EXTI3PB3                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_3,EXTI3,EXTI3_IRQ}
#define EXTI3PC3                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_3,EXTI3,EXTI3_IRQ}
#define EXTI3PD3                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_3,EXTI3,EXTI3_IRQ}


//EXTI4
#define EXTI4PA4                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_4,EXTI4,EXTI4_IRQ}
#define EXTI4PB4                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_4,EXTI4,EXTI4_IRQ}
#define EXTI4PC4                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_4,EXTI4,EXTI4_IRQ}
#define EXTI4PD4                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_4,EXTI4,EXTI4_IRQ}


//EXTI5
#define EXTI5PA5                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_5,EXTI5,EXTI5_IRQ}
#define EXTI5PB5                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_5,EXTI5,EXTI5_IRQ}
#define EXTI5PC5                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_5,EXTI5,EXTI5_IRQ}
#define EXTI5PD5                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_5,EXTI5,EXTI5_IRQ}


//EXTI6
#define EXTI6PA6                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_6,EXTI6,EXTI6_IRQ}
#define EXTI6PB6                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_6,EXTI6,EXTI6_IRQ}
#define EXTI6PC6                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_6,EXTI6,EXTI6_IRQ}
#define EXTI6PD6                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_6,EXTI6,EXTI6_IRQ}


//EXTI7
#define EXTI7PA7                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_7,EXTI7,EXTI7_IRQ}
#define EXTI7PB7                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_7,EXTI7,EXTI7_IRQ}
#define EXTI7PC7                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_7,EXTI7,EXTI7_IRQ}
#define EXTI7PD7                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_7,EXTI7,EXTI7_IRQ}


//EXTI8
#define EXTI8PA8                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_8,EXTI8,EXTI8_IRQ}
#define EXTI8PB8                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_8,EXTI8,EXTI8_IRQ}
#define EXTI8PC8                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_8,EXTI8,EXTI8_IRQ}
#define EXTI8PD8                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_8,EXTI8,EXTI8_IRQ}


//EXTI9
#define EXTI9PA9                (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_9,EXTI9,EXTI9_IRQ}
#define EXTI9PB9                (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_9,EXTI9,EXTI9_IRQ}
#define EXTI9PC9                (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_9,EXTI9,EXTI9_IRQ}
#define EXTI9PD9                (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_9,EXTI9,EXTI9_IRQ}


//EXTI10
#define EXTI10PA10              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_10,EXTI10,EXTI10_IRQ}
#define EXTI10PB10              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_10,EXTI10,EXTI10_IRQ}
#define EXTI10PC10              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_10,EXTI10,EXTI10_IRQ}
#define EXTI10PD10              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_10,EXTI10,EXTI10_IRQ}


//EXTI11
#define EXTI11PA11              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_11,EXTI11,EXTI11_IRQ}
#define EXTI11PB11              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_11,EXTI11,EXTI11_IRQ}
#define EXTI11PC11              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_11,EXTI11,EXTI11_IRQ}
#define EXTI11PD11              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_11,EXTI11,EXTI11_IRQ}


//EXTI12
#define EXTI12PA12              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_12,EXTI12,EXTI12_IRQ}
#define EXTI12PB12              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_12,EXTI12,EXTI12_IRQ}
#define EXTI12PC12              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_12,EXTI12,EXTI12_IRQ}
#define EXTI12PD12              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_12,EXTI12,EXTI12_IRQ}


//EXTI13
#define EXTI13PA13              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_13,EXTI13,EXTI13_IRQ}
#define EXTI13PB13              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_13,EXTI13,EXTI13_IRQ}
#define EXTI13PC13              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_13,EXTI13,EXTI13_IRQ}
#define EXTI13PD13              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_13,EXTI13,EXTI13_IRQ}


//EXTI14
#define EXTI14PA14              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_14,EXTI14,EXTI14_IRQ}
#define EXTI14PB14              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_14,EXTI14,EXTI14_IRQ}
#define EXTI14PC14              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_14,EXTI14,EXTI14_IRQ}
#define EXTI14PD14              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_14,EXTI14,EXTI14_IRQ}


//EXTI15
#define EXTI15PA15              (EXTI_GPIO_Mapping_t){GPIOA,GPIO_PIN_15,EXTI15,EXTI15_IRQ}
#define EXTI15PB15              (EXTI_GPIO_Mapping_t){GPIOB,GPIO_PIN_15,EXTI15,EXTI15_IRQ}
#define EXTI15PC15              (EXTI_GPIO_Mapping_t){GPIOC,GPIO_PIN_15,EXTI15,EXTI15_IRQ}
#define EXTI15PD15              (EXTI_GPIO_Mapping_t){GPIOD,GPIO_PIN_15,EXTI15,EXTI15_IRQ}


/*
 *====================================================================
 *					APIs Functions Declaration
 *====================================================================
 */

void MCAL_EXTI_GPIO_Init(EXTI_pinConfig_t *EXTI_pin);
void MCAL_EXTI_GPIO_DeInit();
void MCAL_EXTI_GPIO_Update(EXTI_pinConfig_t *EXTI_pin);


#endif /* INC_STM32F103X6_EXTI_DRIVER_H_ */
