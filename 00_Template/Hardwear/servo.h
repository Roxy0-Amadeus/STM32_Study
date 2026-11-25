#ifndef __SERVO_H
#define __SERVO_H
#include "PWM.h"

void Servo_Init(void);
static uint8_t Clamp( uint8_t value, uint8_t Max);
void Servo_SetAngle(uint8_t Angle);

#endif
