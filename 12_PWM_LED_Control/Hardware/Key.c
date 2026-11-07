#include "stm32f10x.h"                  // Device header
#include "Delay.h"

uint8_t Key_Num;

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
	Key_Num = 0;
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		Delay_ms(50);
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
		{
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
			Key_Num = 1;
		}
		Delay_ms(50);
	}
	return Key_Num;
}
