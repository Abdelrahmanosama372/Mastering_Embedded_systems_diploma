/*
 * spi_master.c
 *
 * Created: 4/28/2024 8:41:26 AM
 *  Author: Abdelrahman
 */ 

#include "INC/spi_master.h"

void SPI_MasterInit(void)
{
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	SPCR = (1<<SPE)|(1<<MSTR) | (1<<SPR0);
}
void SPI_MasterTransmit(char cData)
{
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)));
}
