#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyDMA.h"

uint8_t DataA[] = {0x01, 0x02, 0x03, 0x04};
uint8_t DataB[] = {0, 0, 0, 0};

int main(void)
{
	OLED_Init();
	MyDMA_Init((uint32_t)DataA, (uint32_t)DataB, 4);	
	
	OLED_ShowString(1, 1, "Amadeus");
	OLED_ShowString(1, 9, "Antonio");
	
	OLED_ShowHexNum(2, 1, (uint32_t)DataA, 8);
	OLED_ShowHexNum(2, 9, (uint32_t)DataB, 8);
	
	OLED_ShowHexNum(3, 1, DataA[0], 2); 
	OLED_ShowHexNum(3, 4, DataA[1], 2);
	OLED_ShowHexNum(3, 7, DataA[2], 2);
	OLED_ShowHexNum(3, 10, DataA[3], 2);
	OLED_ShowHexNum(4, 1, DataB[0], 2);
	OLED_ShowHexNum(4, 4, DataB[1], 2);
	OLED_ShowHexNum(4, 7, DataB[2], 2);
	OLED_ShowHexNum(4, 10, DataB[3], 2);
	
	while(1)
	{
		for(int i = 0; i < 4; i++)
		{
			DataA[i]++;
			
			OLED_ShowHexNum(3, 1, DataA[0], 2); 
			OLED_ShowHexNum(3, 4, DataA[1], 2);
			OLED_ShowHexNum(3, 7, DataA[2], 2);
			OLED_ShowHexNum(3, 10, DataA[3], 2);
			OLED_ShowHexNum(4, 1, DataB[0], 2);
			OLED_ShowHexNum(4, 4, DataB[1], 2);
			OLED_ShowHexNum(4, 7, DataB[2], 2);
			OLED_ShowHexNum(4, 10, DataB[3], 2);
			
			Delay_ms(1000);
			
			MyDMA_Transfer();
			
			OLED_ShowHexNum(3, 1, DataA[0], 2); 
			OLED_ShowHexNum(3, 4, DataA[1], 2);
			OLED_ShowHexNum(3, 7, DataA[2], 2);
			OLED_ShowHexNum(3, 10, DataA[3], 2);
			OLED_ShowHexNum(4, 1, DataB[0], 2);
			OLED_ShowHexNum(4, 4, DataB[1], 2);
			OLED_ShowHexNum(4, 7, DataB[2], 2);
			OLED_ShowHexNum(4, 10, DataB[3], 2);
			
			Delay_ms(1000);
		}
	}
}
