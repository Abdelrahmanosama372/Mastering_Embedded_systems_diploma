/*
 * PWM.h
 *
 * Created: 3/30/2024 1:08:05 PM
 *  Author: Abdelrahman
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <stdint.h>
#include "../../utilies/utilities.h"

typedef enum {
	TIM0_FAST_PWM,
	TIM0_PHASE_CORRECT_PWM,
}TIM0_PWM_Modes;


typedef enum {
	STOPPED=0,
	NON_INVERTING=2,
	INVERTING,
}PWM_Modes;

typedef enum {
	NO_CLOCK=0,
	PRESCALAR_0,
	PRESCALAR_8,
	PRESCALAR_64,
	PRESCALAR_256,
	PRESCALAR_1024,
	EXTERNAL_CLOCK_FALLING_EDGE,
	EXTERNAL_CLOCK_RISING_EDGE,
}Clock_Source;


typedef struct {
	TIM0_PWM_Modes TPWM_Mode;
	Clock_Source clkSource;
	PWM_Modes PWMmode;
	uint8_t OC_val;
}TIM0_Config; 

void TIM0_init(TIM0_Config *config);
void TIM0_deinit();
void set_OC_value(uint8_t OC_val);




#endif /* PWM_H_ */