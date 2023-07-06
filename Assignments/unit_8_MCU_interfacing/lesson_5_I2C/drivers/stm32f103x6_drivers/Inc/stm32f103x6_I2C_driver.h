/*
 * stm32f103x6_I2C_driver.h
 *
 *
 *      Author: Abdelrahman osama
 */

#ifndef INC_STM32F103X6_I2C_DRIVER_H_
#define INC_STM32F103X6_I2C_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103x6_RCC_driver.h"
#include "stm32f103x6_gpio_driver.h"


typedef struct
{
	uint8_t slave_secondary_address_EN; // must be set based on @ref slave secondary address enable
	uint8_t primary_address;
	uint8_t secondary_address;
}slave_address_config;

typedef struct
{
	//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
	//it is reset by software.
	uint8_t Clock_Stretching;         // must be set based on @ref Clock stretching enable/disable
	uint8_t General_Call_Enable;      // must be set based on @ref General call enable/disable
	uint8_t I2C_mode;                 // must be set based on @ref I2C/SMBus mode
	uint8_t I2C_Addressing_Mode;      // must be set based on @ref Addressing mode (slave mode)
	uint8_t Master_mode_selection;    // must be set based on @ref I2C master mode selection
	uint32_t I2C_CLK_speed;            // must be set based on @ref I2C clock speed selection
	slave_address_config slave_address;
    void (*ptr_fun)(void);

}I2C_config;


// Clock stretching enable/disable
#define Clock_stretching_Enable           0
#define Clock_stretching_Disable          1


// General call enable/disable
#define General_call_Disable              0
#define General_call_Enable               1


//Addressing mode (slave mode)
#define I2C_7_bit_address_mode            (0<<15)
#define I2C_10_bit_address_mode           (1<<15)

//I2C master mode selection
#define I2C_SM_Master_mode               0
#define I2C_FM_Master_mode               1

// I2C/SMBus mode
#define I2C_mode_I2C                      0
#define I2C_mode_SMBusn                   1

// slave secondary address enable
#define secondar_address_disable          0
#define secondary_address_enable          1


// I2C clock speed selection
#define I2C_50K_SM_CLK_speed              (50000U)
#define I2C_100K_SM_CLK_speed             (100000U)

// transmit/receive
#define Receive                       1
#define Transmit                      0

typedef enum
{
	with_stop,
	without_stop
}stop_cond;

typedef enum
{
	first_start,
	repeated_start
}start_cond;


typedef enum
{
	EV5,
	EV6,
	EV7,
	EV8,
	EV8_1,
	EV8_2
}status;

typedef enum
{
	RESET,
	SET
}flag_status;

typedef enum
{
	I2C_Master_Transmit,
	I2C_Master_Recieve
}direction;

void MCAL_I2C_init(I2C_TypeDef *I2Cx, I2C_config *I2C_configure);
void MCAL_I2C_deinit(I2C_TypeDef *I2Cx);
void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx, stop_cond stop, start_cond start ,uint8_t slave_address, uint8_t *data, uint32_t datalen);
void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx, stop_cond stop, start_cond start ,uint8_t slave_address, uint8_t *data, uint32_t datalen);
void Generate_Start(I2C_TypeDef *I2Cx, start_cond start);
void Generate_Stop(I2C_TypeDef *I2Cx, stop_cond stop);
flag_status check_events(I2C_TypeDef *I2Cx, status current_status);
void write_Slave_address(I2C_TypeDef *I2Cx, direction direc, uint8_t address);
void MCAL_I2C_Slave_TX(I2C_TypeDef *I2Cx, uint8_t data);
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef *I2Cx, uint8_t data);





#endif /* INC_STM32F103X6_I2C_DRIVER_H_ */
