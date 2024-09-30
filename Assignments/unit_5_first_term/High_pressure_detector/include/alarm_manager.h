
#ifndef ALARM_MANAGER_H
#define ALARM_MANAGER_H

#include "state.h"
#include "driver.h"


void AL_init();

STATE_Define(AL_Busy);

STATE_Define(AL_Idle);

#endif // ALARM_MANAGER_H


