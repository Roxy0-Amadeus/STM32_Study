#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	
	while(1)
	{
		
	}
}
