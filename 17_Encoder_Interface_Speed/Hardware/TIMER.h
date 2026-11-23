#ifndef __TIMER_H
#define __TIMER_H
#include <stdint.h>

void TIMER_Init(void);
uint16_t TIM_Get_Num(void);
void TIM2_IRQHandler(void);

#endif
