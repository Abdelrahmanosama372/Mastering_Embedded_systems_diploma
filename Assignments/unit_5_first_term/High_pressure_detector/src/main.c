#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "pressure_controller.h"
#include "pressure_sensor.h"
#include "alarm_manager.h"


extern void (*AL_state)();
extern void (*PS_state)();
extern void (*PC_state)();

int main (){
	GPIO_INITIALIZATION();
	PS_state = STATE(PS_Busy);
	PC_state = STATE(PC_Busy);
	AL_state = STATE(AL_Idle);
	while (1)
	{
		PS_state();
		PC_state();
		AL_state();
		for(int i=0; i< 100; i++);
	}

}
