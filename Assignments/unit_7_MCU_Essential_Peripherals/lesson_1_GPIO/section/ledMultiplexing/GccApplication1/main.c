/*
 * GccApplication1.c
 *
 * Created: 3/16/2024 11:44:04 AM
 * Author : Abdelrahman
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define  COUNTER 10

int main(void)
{
	DDRC = 0xFC; // 0b11111100
	
    /* Replace with your application code */
    while (1) 
    {
		int i,j;
		/*
		8 leds gets on in order from 0..7 then turn off in order from 7..0
		for (i=0; i<8; i++)
		{
			PORTA |= 1 << i;
			_delay_ms(500);
		}
		
		for (i=7; i>=0; i--)
		{
			PORTA &= ~(1 << i);
			_delay_ms(500);
		}
		*/
		
		/* code for 7-segment multiplexing */
		for(i=0; i<10; i++){
			PORTC = ((i << 4) | 0x8);
			_delay_ms(100);
			for(j=0; j<10; j++){
				PORTC = ((j << 4) | 0x4);
				_delay_ms(100);
			}
		}
		
		
    }
}

