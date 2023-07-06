/*
 * I2C_slave_EEPROM.c
 *
 *  Created on: Jun 21, 2023
 *      Author: Abdelrahman osama
 */

#include "I2C_slave_EEPROM.h"


void EEPROM_init(void)
{
	// I2C configuration
	I2C_config I2C_config;
	I2C_config.Clock_Stretching = Clock_stretching_Disable;
	I2C_config.General_Call_Enable = General_call_Enable;
	I2C_config.I2C_Addressing_Mode = I2C_7_bit_address_mode;
	I2C_config.I2C_CLK_speed = I2C_100K_SM_CLK_speed;
	I2C_config.slave_address.slave_secondary_address_EN = secondar_address_disable;
	I2C_config.slave_address.primary_address = 0x2A;
	I2C_config.I2C_mode = I2C_mode_I2C;
	I2C_config.Master_mode_selection = I2C_SM_Master_mode;

	// initialize I2C communication
	MCAL_I2C_init(I2C1, &I2C_config);
}

void EEPROM_write_Nbytes(uint16_t Memory_address, uint32_t data_len, uint8_t *data)
{
	int i;
	uint8_t buffer[256];
	buffer[0] = (Memory_address >> 8);
	buffer[1] = (uint8_t)Memory_address;
	for(i=0; i<data_len; i++)
	{
		buffer[2+i] = *data;
		data++;
	}
	MCAL_I2C_Master_TX(I2C1, with_stop, first_start, EEPROM_slave_address,buffer, data_len+2);
}
void EEPROM_read_Nbytes(uint16_t Memory_address, uint32_t data_len, uint8_t *data)
{
	uint8_t buffer[2];
	buffer[0] = (Memory_address >> 8);
	buffer[1] = (uint8_t)Memory_address;

	MCAL_I2C_Master_TX(I2C1, without_stop, first_start, EEPROM_slave_address,buffer, address_length);
	MCAL_I2C_Master_RX(I2C1, with_stop, repeated_start, EEPROM_slave_address,data, data_len);;
}
