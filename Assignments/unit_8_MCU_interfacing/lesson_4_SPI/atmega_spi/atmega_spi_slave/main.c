/*
 * atmega_spi_slave.c
 *
 * Created: 4/28/2024 8:38:26 AM
 * Author : Abdelrahman
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "MCAL/INC/spi_slave.h"
#include "util/delay.h"

int main(void)
{
	DDRA = 0xFF;
	SPI_SlaveInit();
	//_delay_ms(500);
  
    while (1) 
    {
		//_delay_ms(1000);
		PORTA = SPI_SlaveReceive();
		_delay_ms(500);
    }
}

