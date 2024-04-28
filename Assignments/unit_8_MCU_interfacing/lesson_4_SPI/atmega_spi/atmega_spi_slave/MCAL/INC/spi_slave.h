/*
 * spi_master.h
 *
 * Created: 4/28/2024 8:41:05 AM
 *  Author: Abdelrahman
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

#include "avr/io.h"

#define DDR_SPI    DDRB
#define DD_MISO    6

void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);


#endif /* SPI_SLAVE_H_ */