/*
 * spi_master.h
 *
 * Created: 4/28/2024 8:41:05 AM
 *  Author: Abdelrahman
 */ 


#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#include <avr/io.h>

#define DDR_SPI			DDRB
#define DD_MOSI			5
#define DD_SCK          7

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);

#endif /* SPI_MASTER_H_ */