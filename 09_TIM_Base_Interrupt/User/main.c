#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "TIMER.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	TIMER_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowString(2, 3, "Num:");
	
	
	
	while(1)
	{	
		uint16_t current_Num = TIM_Get_Num();
		OLED_ShowNum(2, 7, current_Num, 5);
	}
}
