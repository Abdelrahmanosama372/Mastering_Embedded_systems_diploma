/*
 * PWM.c
 *
 * Created: 3/30/2024 1:07:52 PM
 *  Author: Abdelrahman
 */ 

#include "inc/PWM.h"

void TIM0_init(TIM0_Config *config){
	DDRB = 0xFF;
	switch(config->TPWM_Mode){
		case TIM0_FAST_PWM:
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
			
		case TIM0_PHASE_CORRECT_PWM:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
	}
	
	//set mode
	TCCR0 |= (0x3 << 4);
	
	//set Output compare value
	OCR0 = config->OC_val;
	
	//set clock
	TCCR0 |= config->clkSource ;
}

void TIM0_deinit(){
	TCCR0 &= ~(0x7);
}

void set_OC_value(uint8_t OC_val){
	OCR0 = OC_val;
}