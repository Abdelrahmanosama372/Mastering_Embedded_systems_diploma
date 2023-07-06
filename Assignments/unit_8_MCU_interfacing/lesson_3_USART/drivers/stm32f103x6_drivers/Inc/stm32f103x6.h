/*
 * stm32f103x6.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Abdelrahman osama
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_Memory_BASE                         0x08000000UL
#define System_Memory_BASE                        0x1FFFF000UL
#define SRAM_BASE            			          0x20000000UL

#define Cortex_M3_Intenal_Peripherals_BASE        0xE0000000UL
#define NVIC_BASE                                 0xE000E100UL
#define NVIC_ISER0           *((volatile uint32_t *) (NVIC_BASE + 0x000))
#define NVIC_ISER1           *((volatile uint32_t *) (NVIC_BASE + 0x004))
#define NVIC_ISER2           *((volatile uint32_t *) (NVIC_BASE + 0x008))
#define NVIC_ICER0           *((volatile uint32_t *) (NVIC_BASE + 0x080))
#define NVIC_ICER1           *((volatile uint32_t *) (NVIC_BASE + 0x084))
#define NVIC_ICER2           *((volatile uint32_t *) (NVIC_BASE + 0x088))

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE             0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

// A,B fully included in package LQFP4
#define GPIOA_BASE           0x40010800UL
#define GPIOB_BASE           0x40010C00UL
// C,D partially included in package LQFP4
#define GPIOC_BASE           0x40011000UL
#define GPIOD_BASE           0x40011400UL
// E not included in package LQFP4
#define GPIOE_BASE           0x40011800UL

#define EXTI_BASE            0x40010400UL
#define AFIO_BASE            0x40010000UL

#define USART1_BASE          0x40013800UL
#define SPI1_BASE            0x40013000UL

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

#define USART2_BASE          0x40004400UL
#define USART3_BASE          0x40004800UL
#define I2C1_BASE            0x40005400UL
#define I2C2_BASE            0x40005800UL
#define SPI2_BASE            0x40003800UL
#define TIM2_BASE            0x40000000UL
#define TIM3_BASE 			 0x40000400UL
#define TIM4_BASE			 0x40000800UL

//-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
    uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: I2C
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
}I2C_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: SPI
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: TIMER->TIM2_TO_5
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RESERVED;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t RESERVED_2;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
}TIM2_5_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)

#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define AFIO                ((AFIO_TypeDef *) AFIO_BASE)

#define RCC                 ((RCC_TypeDef  *) RCC_BASE)

//UARTS
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)

// I2C
#define I2C1               	((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)

// SPI
#define SPI1         		((SPI_TypeDef *) SPI1_BASE)
#define SPI2				((SPI_TypeDef *) SPI2_BASE)

// TIMERS
#define TIM2                ((TIM2_5_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM2_5_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM2_5_TypeDef *) TIM4_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_ENABLE()     (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_ENABLE()     (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_ENABLE()     (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_ENABLE()     (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_ENABLE()     (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_ENABLE()      (RCC->APB1ENR |= 1<<0)

#define RCC_USART1_ENABLE()    (RCC->APB2ENR |= 1<<14)
#define RCC_USART2_ENABLE()    (RCC->APB1ENR |= 1<<17)
#define RCC_USART3_ENABLE()    (RCC->APB1ENR |= 1<<18)

#define RCC_I2C1_ENABLE()      (RCC->APB1ENR |= 1<<21)
#define RCC_I2C2_ENABLE()      (RCC->APB1ENR |= 1<<22)

#define RCC_SPI1_ENABLE()      (RCC->APB2ENR |= 1<<12)
#define RCC_SPI2_ENABLE()      (RCC->APB1ENR |= 1<<14)

#define RCC_TIM2_ENABLE()      (RCC->APB1ENR |= 1<<0)
#define RCC_TIM3_ENABLE()      (RCC->APB1ENR |= 1<<1)
#define RCC_TIM4_ENABLE()      (RCC->APB1ENR |= 1<<2)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Reset Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define  RCC_I2C1_RESET        (RCC->APB1RSTR |= 1<<21)
#define  RCC_I2C2_RESET        (RCC->APB1RSTR |= 1<<22)

#define RCC_USART1_RESET()    (RCC->APB2RSTR |= 1<<14)
#define RCC_USART2_RESET()    (RCC->APB1RSTR |= 1<<17)
#define RCC_USART3_RESET()    (RCC->APB1RSTR |= 1<<18)

#define RCC_SPI1_RESET()      (RCC->APB2RSTR |= 1<<12)
#define RCC_SPI2_RESET()      (RCC->APB1RSTR |= 1<<14)

#define RCC_TIM2_RESET()      (RCC->APB1RSTR |= 1<<0)
#define RCC_TIM3_RESET()      (RCC->APB1RSTR |= 1<<1)
#define RCC_TIM4_RESET()      (RCC->APB1RSTR |= 1<<2)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//IVT
//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI
#define EXTI0_IRQ               6
#define EXTI1_IRQ               7
#define EXTI2_IRQ               8
#define EXTI3_IRQ               9
#define EXTI4_IRQ               10
#define EXTI5_IRQ               23
#define EXTI6_IRQ               23
#define EXTI7_IRQ               23
#define EXTI8_IRQ               23
#define EXTI9_IRQ               23
#define EXTI10_IRQ              40
#define EXTI11_IRQ              40
#define EXTI12_IRQ              40
#define EXTI13_IRQ              40
#define EXTI14_IRQ              40
#define EXTI15_IRQ              40





//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC EXTI IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_ENABLE             (NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE             (NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE             (NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE             (NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE            (NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_ENABLE          (NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_ENABLE         (NVIC_ISER1 |= 1<<8)  //40-32

#define NVIC_IRQ6_EXTI0_DISABLE             (NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE             (NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE             (NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE             (NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE            (NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_DISABLE          (NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_DISABLE         (NVIC_ICER1 |= 1<<8)  //40-32

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC USART IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ37_USART1_ENABLE             (NVIC_ISER1 |= 1<<5) // 37-32 = 5
#define NVIC_IRQ38_USART2_ENABLE             (NVIC_ISER1 |= 1<<6)
#define NVIC_IRQ39_USART3_ENABLE             (NVIC_ISER1 |= 1<<7)

#define NVIC_IRQ37_USART1_DISABLE            (NVIC_ICER1 |= 1<<5)
#define NVIC_IRQ38_USART2_DISABLE            (NVIC_ICER1 |= 1<<6)
#define NVIC_IRQ39_USART3_DISABLE            (NVIC_ICER1 |= 1<<7)


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC I2C IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ31_I2C1_EV_ENABLE             (NVIC_ISER0 |= 1<<31)
#define NVIC_IRQ32_I2C1_ER_ENABLE             (NVIC_ISER1 |= 1<<0)
#define NVIC_IRQ31_I2C1_EV_DISABLE            (NVIC_ICER0 |= 1<<31)
#define NVIC_IRQ32_I2C1_ER_DISABLE            (NVIC_ICER1 |= 1<<0)

#define NVIC_IRQ33_I2C2_EV_ENABLE             (NVIC_ISER1 |= 1<<1) // 33-32 = 1
#define NVIC_IRQ34_I2C2_ER_ENABLE             (NVIC_ISER1 |= 1<<2)
#define NVIC_IRQ33_I2C2_EV_DISABLE            (NVIC_ICER1 |= 1<<1)
#define NVIC_IRQ34_I2C2_ER_DISABLE            (NVIC_ICER1 |= 1<<2)


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC SPI IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ35_SPI1_ENABLE             (NVIC_ISER1 |= 1<<3) // 35-32 = 3
#define NVIC_IRQ36_SPI2_ENABLE             (NVIC_ISER1 |= 1<<4)

#define NVIC_IRQ35_SPI1_DISABLE            (NVIC_ICER1 |= 1<<3)
#define NVIC_IRQ36_SPI2_DISABLE            (NVIC_ICER1 |= 1<<4)

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC TIM2_to_5 IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ28_TIM2_ENABLE             (NVIC_ISER0 |= 1<<28)
#define NVIC_IRQ29_TIM3_ENABLE             (NVIC_ISER0 |= 1<<29)
#define NVIC_IRQ30_TIM4_ENABLE             (NVIC_ISER0 |= 1<<30)

#define NVIC_IRQ28_TIM2_DISABLE            (NVIC_ICER0 |= 1<<28)
#define NVIC_IRQ29_TIM3_DISABLE            (NVIC_ICER0 |= 1<<29)
#define NVIC_IRQ30_TIM4_DISABLE            (NVIC_ICER0 |= 1<<30)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */

#endif /* INC_STM32F103X6_H_ */
