#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"

uint8_t i = 0;
uint8_t Key_State = 0;
uint8_t LED_Out(void);

int main(void)
{
	OLED_Init();
	PWM_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	
	PWM_SetCompare1(i);
	while(1)
	{
		if(Key_GetNum() == 1)
		{	
			i += 10;
			if(i >= 100)
			{
				i = 0;
			}
			PWM_SetCompare1(i);
		}
		OLED_ShowNum(2, 1, i, 3);
	}
}
