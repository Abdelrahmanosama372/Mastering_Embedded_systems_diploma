/*
 * main.c
 *
 * Created: 3/17/2024 12:15:30 PM
 * Author : Abdelrahman
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "Lcd/lcd.h"
#include "keyPad/keyPad.h"

int main(void)
{
	LCD_init();
	LCD_writeString("LEARN IN DEPTH");
	_delay_ms(1000);
	LCD_backClearDisplay();
	LCD_writeString("ABDEL RAHMAN");
    /* Replace with your application code */
    while (1) 
    {

    }
}

