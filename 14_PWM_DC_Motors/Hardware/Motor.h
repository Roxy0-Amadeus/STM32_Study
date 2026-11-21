#ifndef __MOTOR_H
#define __MOTOR_H
#include <stdint.h>

void Motor_Init(void);
void Motor_SetSpeed(int16_t Speed);
int16_t Motor_GetNextSpeed(void);

#endif
