/*
 * spi_slave.c
 *
 * Created: 4/28/2024 8:41:26 AM
 *  Author: Abdelrahman
 */ 

#include "INC/spi_slave.h"

void SPI_SlaveInit(void)
{
	DDR_SPI = (1<<DD_MISO);
	SPCR = (1<<SPE);
}
char SPI_SlaveReceive(void)
{
	SPDR = 30;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}