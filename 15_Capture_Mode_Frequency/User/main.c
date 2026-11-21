#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

uint8_t i;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	PWM_SetPrescaler(719);			//Freq = 72M/(PSC+1)/(ARR+1)
	PWM_SetCompare1(50);			//Duty = CCR/(ARR+1)
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowString(2, 1, "Freq:00000Hz");
	
	while(1)
	{
		OLED_ShowNum(2, 6, IC_GetFreq(), 5);
	}
}
