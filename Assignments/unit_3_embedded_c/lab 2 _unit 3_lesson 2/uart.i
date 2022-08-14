# 1 "uart.c"
# 1 "<command-line>"
# 1 "uart.c"




void uart_send_string (unsigned char ptr_tx_string);




void uart_send_string (unsigned char ptr_tx_string)
{
 while (*ptr != '\0')
 {
  (volatile unsigned int * const)((unsigned int *) 0x101f1000) = (unsigned int) (*ptr_tx_string);
  ptr_tx_string++;
 }
}
