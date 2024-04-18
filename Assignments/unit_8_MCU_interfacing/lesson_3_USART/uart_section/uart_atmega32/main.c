/*
 * uart_atmega32.c
 *
 * Created: 4/16/2024 8:23:56 AM
 * Author : Abdelrahman
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "MCAL/INC/Uart.h"
#include "HAL/INC/lcd.h"

int main(void)
{
	// enable interrupts
	sei();
	
	LCD_init();
	
	UART_Config config;
	config.data_size = UART_DATA_SIZE_8_BIT;
	config.baudrate = UART_BAUDRATE_9600;
	config.Uart_mode = UART_MODE_Tx_AND_RX;
	config.parity_mode = UART_PARITY_DISABLED;
	config.stop_bits_number = UART_STOP_BIT_ONE_BIT;
	config.Uart_interrupt_mode = UART_INTERRUPT_RXC_AND_TXC;
	
	Uart_init(&config);
	
	uint8_t data[] = "hello world";
	Uart_send_async(&data, 12);
	
	uint8_t data2[100] = {0};
	data2[11] = '\0';
	Uart_receive_async(&data2);
 
    while (1) 
    {
		_delay_ms(10000);
		//uint8_t data[40]; 
		//Uart_receive_string(&data,sizeof(data));
		LCD_writeString(&data2);
    }
}

