#include "uart.h"

unsigned char string_buffer[100] = "Learn in depth: Abdelrahman";

void main (void)
{
	uart_send_string (string_buffer);
}