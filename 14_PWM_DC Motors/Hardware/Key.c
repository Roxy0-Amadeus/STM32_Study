#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t Key_Val = 0;
	static uint8_t Key_case = 0;
	uint8_t Get_Key = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15);
	
	switch(Key_case)
	{
		case 0:
			if(Get_Key == 0)
			{
				Key_case = 1;
			}
			break;
		case 1:
			if(Get_Key == 0)
			{
				Key_Val = 1;
				Key_case = 2;
			}
			else
			{	
				Key_case = 0;
			}
			break;
		case 2:
			if(Get_Key == 1)
			{	
				Delay_ms(10);
				Key_case = 0;
			}
			break;
	}
	return Key_Val;
}
