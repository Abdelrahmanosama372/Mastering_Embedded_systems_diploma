/*
 * timerPWM.c
 *
 * Created: 3/30/2024 1:07:16 PM
 * Author : Abdelrahman
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "MCAL/inc/PWM.h"
#include <util/delay.h>

int main(void)
{
	TIM0_Config config;
	config.clkSource = PRESCALAR_64;
	config.TPWM_Mode = TIM0_FAST_PWM;
	config.PWMmode = INVERTING;
	config.OC_val = 0;
	_delay_ms(1000);
	TIM0_init(&config);
    /* Replace with your application code */
    while (1) 
    {	
		for (int i=255; i>=0; i--){
			set_OC_value(i);
			_delay_ms(10);
		}
		
		for (int i=255; i>=0; i--){
			set_OC_value(i);
			_delay_ms(10);
		}
		
		
    }
}

