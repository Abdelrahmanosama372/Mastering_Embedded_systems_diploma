/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman osama
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32f103x6.h"
#include "I2C_slave_EEPROM.h"


int main(void)
{

	uint8_t data[4] = {0x01,0x02,0x03,0x04};
	uint8_t received_bytes[4] = {0};

	EEPROM_init();

	// write to the EEPROM
	EEPROM_write_Nbytes(0x4578, sizeof(data), data);
	// read from the EEPROM
	EEPROM_read_Nbytes(0x4578, sizeof(data), received_bytes);
	
	while(1)
	{
		


	}
}

