/*
 * temperatureMonitor.c
 *
 * Created: 3/27/2024 10:16:32 AM
 * Author : Abdelrahman
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "ADC/ADC.h"
#include "Lcd/lcd.h"

uint8_t calculate_temp_val();

int main(void)
{
	LCD_init();
	ADC_init(VREF_VCC,PRESCALAR_4);
	LCD_writeString("Temperature:");
    uint8_t prev_temp_val = calculate_temp_val();
	uint8_t curr_temp_val;
	LCD_goTo_X_and_Y(1,0);
	LCD_writeInteger(prev_temp_val);
	
    while (1) 
    {
		curr_temp_val = calculate_temp_val();
		if(curr_temp_val != prev_temp_val){
			LCD_goTo_X_and_Y(1,0);
			LCD_writeInteger(curr_temp_val);
			prev_temp_val = curr_temp_val;		
		}
	}
}

uint8_t calculate_temp_val(){
	return (ADC_read(ADC_CHANNEL_0)*500)/1024;
}
