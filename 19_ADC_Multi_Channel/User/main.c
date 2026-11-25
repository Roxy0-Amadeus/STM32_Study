#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t AD0, AD2, AD4;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowString(2, 1, "AD0:");
	OLED_ShowString(3, 1, "AD2:");
	OLED_ShowString(4, 1, "AD4:");
	
	while(1)
	{
		AD0 = AD_GetValue(ADC_Channel_0);
		AD2 = AD_GetValue(ADC_Channel_2);
		AD4 = AD_GetValue(ADC_Channel_4);
		
		OLED_ShowNum(2, 5, AD0, 4);
		OLED_ShowNum(3, 5, AD2, 4);
		OLED_ShowNum(4, 5, AD4, 4);
	}
}
