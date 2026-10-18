#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowChar(1, 2, 'n');
	OLED_ShowChar(1, 3, 't');
	OLED_ShowChar(1, 4, 'o');
	OLED_ShowChar(1, 5, 'n');
	OLED_ShowChar(1, 6, 'i');
	OLED_ShowChar(1, 7, 'o');
	OLED_ShowString(4, 10, "Amadeus");
	OLED_ShowString(2, 10, "(*^_^*)");
	OLED_ShowString(3, 1, "<(TVT)>"); 
	while(1)
	{
		
	}
}
