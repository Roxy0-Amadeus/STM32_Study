#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t AD_Value;
uint16_t voltage_cV;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowString(2, 1, "AD_Value:");
	OLED_ShowString(3, 1, "Volatage:0.00v");
	
	while(1)
	{
		AD_Value = AD_GetValue();
		voltage_cV = ((uint32_t)AD_Value *330U + 2047U) / 4095U;
		OLED_ShowNum(2, 10, AD_Value, 4);
		OLED_ShowNum(3, 10, voltage_cV / 100, 1);
		OLED_ShowNum(3, 12, voltage_cV % 100, 2);
	}
}
