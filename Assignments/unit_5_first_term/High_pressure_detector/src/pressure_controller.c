#include "pressure_controller.h"
#include "state.h"

#include "pressure_sensor.h"
#include "alarm_manager.h"
#include <stdio.h>


extern void (*PS_state)();
extern void (*AL_state)();

void (*PC_state)();

enum {
  PC_Busy,
  PC_HighPressure,
  PC_Waiting,
}PC_state_id;

STATE_Define(PC_Busy)
{
  PC_state_id = PC_Busy;
  // signal the pressure sensor to read new reading
  PS_state = STATE(PS_Busy);
}

STATE_Define(PC_HighPressure)
{
  PC_state_id = PC_HighPressure;
  AL_state = STATE(AL_Busy);
}

