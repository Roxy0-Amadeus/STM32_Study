#ifndef __COUNT_SENSOR_H
#define __COUNT_SENSOR_H
#include <stdint.h>

void CountSensor_Init(void);
uint16_t CountSensor_Get(void);
uint8_t Get_Sensor_Flag(void);
void Clear_Sensor_Flag(void);
void CountSensor_Increase(void);

#endif
