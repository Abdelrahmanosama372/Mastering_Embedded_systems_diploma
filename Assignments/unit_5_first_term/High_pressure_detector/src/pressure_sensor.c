
#include "pressure_sensor.h"
#include "driver.h"
#include <stdio.h>
#include "pressure_controller.h"
#include "state.h"

void (*PS_state)();

extern void (*PC_state)();

enum {
    PS_Busy,
    PS_Idle,
}PS_state_id;

STATE_Define(PS_Busy)
{
  PS_state_id = PS_Busy;
  int PS_reading = getPressureVal();

  if(PS_reading > 20)
  {
    PC_state = STATE(PC_HighPressure);
  }
  PS_state = STATE(PS_Idle);
}

STATE_Define(PS_Idle)
{
  PS_state_id = PS_Idle;
  asm("nop");
}



