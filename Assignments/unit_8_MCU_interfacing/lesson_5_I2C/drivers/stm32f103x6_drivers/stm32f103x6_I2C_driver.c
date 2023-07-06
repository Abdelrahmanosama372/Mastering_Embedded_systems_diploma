/*
 * stm32f103x6_I2C_driver.c
 *
 *
 *      Author: Abdelrahman osama
 */

#include "stm32f103x6_I2C_driver.h"


void I2C_GPIO_config(I2C_TypeDef *I2Cx)
{
	RCC_GPIOB_ENABLE();
	GPIO_Pin_Config pin_config;

	// configure GPIO pins as Alternative function output open drain
	if (I2Cx == I2C1)
		{
			pin_config.Pin_Mode = Alternate_Function_Output_OD;
			pin_config.Pin_Number = GPIO_PIN_6;
			pin_config.Pin_Speed = GPIO_Pin_Max_Speed10M;
			MCAL_GPIO_Init(GPIOB, &pin_config);

			pin_config.Pin_Mode = Alternate_Function_Output_OD;
			pin_config.Pin_Number = GPIO_PIN_7;
			pin_config.Pin_Speed = GPIO_Pin_Max_Speed10M;
			MCAL_GPIO_Init(GPIOB, &pin_config);

		}
		else
		{
			pin_config.Pin_Mode = Alternate_Function_Output_OD;
			pin_config.Pin_Number = GPIO_PIN_10;
			pin_config.Pin_Speed = GPIO_Pin_Max_Speed10M;
			MCAL_GPIO_Init(GPIOB, &pin_config);

			pin_config.Pin_Mode = Alternate_Function_Output_OD;
			pin_config.Pin_Number = GPIO_PIN_11;
			pin_config.Pin_Speed = GPIO_Pin_Max_Speed10M;
			MCAL_GPIO_Init(GPIOB, &pin_config);
		}
}

void MCAL_I2C_init(I2C_TypeDef *I2Cx, I2C_config *I2C_configure)
{
	uint32_t PCLK;

	I2C_GPIO_config(I2Cx);

	// enable clock for I2C peripheral
	if (I2Cx == I2C1)
	{
		RCC_I2C1_ENABLE();

	}
	else
	{
		RCC_I2C2_ENABLE();
	}


	PCLK = MCAL_RCC_get_PCLK1(RCC);
// Configure the clock control register
	I2Cx->CCR &= ~(0x1F << 0);
	I2Cx->CCR |= (uint32_t) (PCLK/(2*I2C_configure->I2C_CLK_speed));
	I2Cx->CCR &= ~(1<<15);

// configure the I2Cx-
	I2Cx->CR2 |= (uint32_t) (PCLK/1000000);

// Configure the rise time register
	I2Cx->TRISE &= ~(0x3F);
	I2Cx->TRISE |= (uint32_t) ((PCLK/1000000) + 1);

	if (I2C_configure -> slave_address.slave_secondary_address_EN == secondary_address_enable)
	{
		// put primary slave address
		I2Cx->OAR1 |= (I2C_configure->slave_address.primary_address << 1);
		// put secondary slave address
		I2Cx->OAR2 |= (I2C_configure->slave_address.secondary_address << 1);
	}
	else
	{
		// put primary slave address
		I2Cx->OAR1 |= (I2C_configure->slave_address.primary_address << 1);
	}

// configure addressing mode
	I2Cx->OAR1 &= ~(1 << 15);
	I2Cx->OAR1 |= I2C_configure->I2C_Addressing_Mode;

// Program the I2C_CR1 register to enable the peripheral
	I2Cx->CR1 |= I2C_CR1_PE_Msk;

// enable Acknowledge
	I2Cx->CR1 |= I2C_CR1_ACK_Msk;

}

void MCAL_I2C_deinit(I2C_TypeDef *I2Cx)
{

	if (I2Cx == I2C1)
	{
		// disable interrupt for I2C1
		NVIC_IRQ31_I2C1_EV_DISABLE;
		NVIC_IRQ32_I2C1_ER_DISABLE;
		// reset I2C1
		RCC_I2C1_RESET;
	}
	else
	{
		// disable interrupt for I2C2
		NVIC_IRQ33_I2C2_EV_DISABLE;
		NVIC_IRQ34_I2C2_ER_DISABLE;
		// reset I2C2
		RCC_I2C2_RESET;
	}

}

void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx, stop_cond stop, start_cond start,uint8_t slave_address, uint8_t *data, uint32_t datalen)
{
	int i;
	//	• Set the START bit in the I2C_CR1 register to generate a Start condition
	Generate_Start(I2Cx,start);
	// check EV5
	while(!(check_events(I2Cx, EV5)));
	// write slave address
	write_Slave_address(I2Cx, I2C_Master_Transmit, slave_address);
	while((I2Cx->SR1 & I2C_SR1_AF_Msk));
	// check EV6
	while(!(check_events(I2Cx, EV6)));
	// check EV8_1 (data register empty)
	while(check_events(I2Cx, EV8_1));
	while(check_events(I2Cx, EV8));
	// write data to data register
	for(i=0; i<datalen;i++)
	{
		I2Cx->DR = *data;
		data++;
		// check for ACK failure
		while((I2Cx->SR1 & I2C_SR1_AF_Msk));
		// TXE check
		while(check_events(I2Cx, EV8));
	}
	// check last byte transmission
	while(check_events(I2Cx, EV8_2));
	Generate_Stop(I2Cx,stop);
}

void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx, stop_cond stop, start_cond start,uint8_t slave_address, uint8_t *data, uint32_t datalen)
{
	int i;
	//	• Set the START bit in the I2C_CR1 register to generate a Start condition
	Generate_Start(I2Cx,start);
	// check EV5
	while(!(check_events(I2Cx, EV5)));
	// write slave address
	write_Slave_address(I2Cx, I2C_Master_Recieve, slave_address);
	while((I2Cx->SR1 & I2C_SR1_AF_Msk));
	// check EV6
	while(!(check_events(I2Cx, EV6)));

	// receive data
	for(i=0; i<datalen;i++)
	{
		// check EV7 (data register not empty)
		while(check_events(I2Cx, EV7));
		// read data
		*data = I2Cx->DR;
		data++;
		if(i == datalen-2)
		{
			// disable ACK (stop receiving)
			I2Cx->CR1 &= ~(I2C_CR1_ACK_Msk);
			// generate stop condition
			Generate_Stop(I2Cx,stop);
		}
	}



	// Enable ACK (stop receiving)
	I2Cx->CR1 |= (I2C_CR1_ACK_Msk);
}

void Generate_Start(I2C_TypeDef *I2Cx, start_cond start)
{
	if (start == first_start)
	{
		// check bus is not busy
		if(!(I2Cx->SR2 & I2C_SR2_BUSY_Msk))
		{
			// start generation
			I2Cx->CR1 |= I2C_CR1_START_Msk;
		}
	}
	else
	{
		// repeated start generation
		I2Cx->CR1 |= I2C_CR1_START_Msk;
	}
}

void Generate_Stop(I2C_TypeDef *I2Cx, stop_cond stop)
{
	if( stop == with_stop)
	{
		I2Cx->CR1 |= I2C_CR1_STOP_Msk;
	}
	else
	{
		I2Cx->CR1 &= (~I2C_CR1_STOP_Msk);
	}
}

flag_status check_events(I2C_TypeDef *I2Cx, status current_status)
{
	volatile uint32_t dummy_read;
	flag_status bit_status = RESET;
	switch(current_status)
	{
	case EV5:
		//cleared by reading SR1 register followed by writing DR register with Address.
		if(I2Cx->SR1 &= I2C_SR1_SB_Msk)
			bit_status = SET;
		else
			bit_status = RESET;

		break;
	case EV6:
		//cleared by reading SR1 register followed by reading SR2.
		if (I2Cx->SR1 &= I2C_SR1_ADDR_Msk)
		{
			dummy_read = I2Cx->SR1;
			dummy_read = I2Cx->SR2;
			bit_status = SET;
		}
		else
		{
			bit_status = RESET;
		}

		break;

	case EV7:
		if(I2Cx->SR1 &= I2C_SR1_RXNE_Msk)

			bit_status = RESET;
		else
			bit_status = SET;
		break;
	case EV8:
	case EV8_1:
		dummy_read = I2Cx->SR1;
		dummy_read = I2Cx->SR2;
		if(I2Cx->SR1 &= I2C_SR1_TXE_Msk)
		{

			bit_status = RESET;
		}
		else
			bit_status = SET;
		break;
	case EV8_2:
		if(I2Cx->SR1 &= I2C_SR1_BTF_Msk)

			bit_status = RESET;
		else
			bit_status = SET;
	break;
	}
	return bit_status;
}

void write_Slave_address(I2C_TypeDef *I2Cx, direction direc, uint8_t address)
{
	if(direc == I2C_Master_Transmit)
	{
		I2Cx->DR = ((address << 1) | (I2C_Master_Transmit));
	}
	else
	{
		I2Cx->DR = ((address << 1) | (I2C_Master_Recieve));
	}
}

void MCAL_I2C_Slave_TX(I2C_TypeDef *I2Cx, uint8_t data)
{
	I2Cx->DR = data;
}

uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef *I2Cx, uint8_t data)
{
	return (I2Cx->DR);
}
