/*
 * I2C_slave_EEPROM.h
 *
 *  Created on: Jun 21, 2023
 *      Author: Abdelrahman osama
 */

#ifndef INC_I2C_SLAVE_EEPROM_H_
#define INC_I2C_SLAVE_EEPROM_H_

#include "stm32f103x6_I2C_driver.h"

#define EEPROM_slave_address    0x2A
#define address_length          2     // 2 bytes

//-------------------- APIS --------------------
void EEPROM_init(void);
void EEPROM_write_Nbytes(uint16_t Memory_address, uint32_t data_len, uint8_t *data);
void EEPROM_read_Nbytes(uint16_t Memory_address, uint32_t data_len, uint8_t *data);

#endif /* INC_I2C_SLAVE_EEPROM_H_ */
