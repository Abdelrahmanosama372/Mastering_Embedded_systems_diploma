/*
 * atmega_spi_master.c
 *
 * Created: 4/28/2024 8:37:34 AM
 * Author : Abdelrahman
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "MCAL/INC/spi_master.h"
#include "util/delay.h"

int main(void)
{
   char count = 0; 
   SPI_MasterInit();
   //_delay_ms(500);
    while (1) 
    {
		SPI_MasterTransmit(count++);
		_delay_ms(500);
    }
}

