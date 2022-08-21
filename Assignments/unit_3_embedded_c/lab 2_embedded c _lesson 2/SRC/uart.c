//include "uart.h"
#define  UART0DR     *(volatile unsigned int * const)((unsigned int *) 0x101f1000)

void uart_send_string (unsigned char* ptr_tx_string)
{
	while (*ptr_tx_string != '\0')
	{
		UART0DR = (unsigned int) (*ptr_tx_string);
		ptr_tx_string++;
	}
} 