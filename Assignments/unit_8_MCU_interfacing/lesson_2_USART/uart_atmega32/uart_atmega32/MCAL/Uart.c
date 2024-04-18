/*
 * Uart.c
 *
 * Created: 4/16/2024 8:27:38 AM
 *  Author: Abdelrahman
 */ 


#include "INC/Uart.h"
#include "INC/utilities.h"

UART_Config *GP_config;
static uint8_t* GP_data_send;
static uint32_t GP_data_size;

static uint8_t* GP_data_recv;
static uint32_t GP_data_counter;

void Uart_init(UART_Config *config) {
	GP_config = config;
	
	// set data size
	SET_BIT(UCSRC,URSEL);
	UCSRC |= config->data_size << 1;
	if (config->data_size == UART_DATA_SIZE_9_BIT){
		SET_BIT(UCSRA,U2X);
	}
		
	// set baud rate
	CLEAR_BIT(UCSRA,U2X);
	UBRRL = config->baudrate;
		
    // set parity mode
	SET_BIT(UCSRC,URSEL);
	UCSRC |= config->parity_mode << 4;
	
	// set stop bits number
	SET_BIT(UCSRC,URSEL);
	UCSRC |= config->stop_bits_number << 3;
	
	// set UART mode
	UCSRB |= config->Uart_mode << 3;
	
	// interrupt enable/disable
	UCSRB |= GP_config->Uart_interrupt_mode << 6;
}

void Uart_send_char(uint8_t data) {
	while(!READ_BIT(UCSRA,UDRE));
		UDR = data;
}

void Uart_send_string(uint8_t* str, uint32_t size) {
	int i;
	for(i=0; i<size; i++){
		Uart_send_char(str[i]);
	}
}

uint8_t Uart_receive_char() {
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}


void Uart_receive_string(uint8_t* str, uint32_t size) {
	int i;
	for (i=0; i < size -2; i++) {
		uint8_t ch = Uart_receive_char();
		if (ch == '\r') 
			break;
		str[i] = ch;
	}
	str[i] = '\0';
}

void Uart_send_async(uint8_t* data, uint32_t size) {
	if(GP_config->Uart_interrupt_mode == UART_INTERRUPT_DISABLE)
		return;
	GP_data_send = data;
	GP_data_size = size;
	UDR = GP_data_send[0];
}

void Uart_receive_async(uint8_t* data) {
	if(GP_config->Uart_interrupt_mode == UART_INTERRUPT_DISABLE)
		return;
	GP_data_recv = data;
	GP_data_counter = 0;
}

ISR(USART_TXC_vect){
	static uint32_t i=1;
	if(i < GP_data_size){
		UDR = GP_data_send[i++];
	}else {
		i = 1;
	}
}

ISR(USART_RXC_vect){
	GP_data_recv[GP_data_counter++] = UDR;
}