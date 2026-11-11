#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"

int main(void)
{	
	uint8_t Key_Num = 0;
	int16_t Speed = 0;
	
	OLED_Init();
	Motor_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	
	Motor_SetSpeed(0);
	OLED_ShowSignedNum(2, 4, Speed, 3);
	Delay_ms(1000);
	
	while(1)
	{
		Key_Num = Key_GetNum();
		                        
		if(Key_Num == 1)
		{
			Speed = Motor_GetNextSpeed();
			Motor_SetSpeed(Speed);
			OLED_ShowSignedNum(2, 4, Speed, 3);
		}
		
	}
}
