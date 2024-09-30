#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include "state.h"

void PS_init();

STATE_Define(PS_Busy);
STATE_Define(PS_Idle);

#endif // !PRESSURE_SENSOR_H
