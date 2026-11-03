#ifndef __TIMER_H
#define __TIMER_H
#include <stdint.h>

void TIMER_Init(void);
uint16_t TIM_GetNum(void);
void TIM2_IRQHandler(void);
uint16_t Timer_GetCounter(void);

#endif
