#include "alarm_manager.h"
#include "state.h"
#include "pressure_controller.h"
#include <stdio.h>

extern void (*PC_state)();

void (*AL_state)();

enum {
  AL_Busy,
  AL_Idle,
}AL_Status_Id;

void AL_init()
{
  // init Alarm driver
}

STATE_Define(AL_Busy)
{
  AL_Status_Id = AL_Busy;
  Set_Alarm_actuator(0);
  Delay(600000);
  Set_Alarm_actuator(1);
  AL_state = STATE(AL_Idle);
  PC_state = STATE(PC_Busy);
}

STATE_Define(AL_Idle)
{
  AL_Status_Id = AL_Idle;
  asm("nop");
}
