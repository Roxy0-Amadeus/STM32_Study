#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//端口输出模式，这里是推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	while(1)
	{
		GPIO_Write(GPIOB, ~0x1000);
		Delay_ms(200);
		GPIO_Write(GPIOB, ~0x0000);
		Delay_ms(200);
		GPIO_Write(GPIOB, ~0x1000);
		Delay_ms(200);
		GPIO_Write(GPIOB, ~0x0000);
		Delay_ms(700);
	}
}
