#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//端口输出模式，这里是推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//	GPIO_ResetBits(GPIOA, GPIO_Pin_0);		//置低电平
	
//	GPIO_SetBits(GPIOA, GPIO_Pin_0);		//置高电平
	
	//GPIO_WritBit可以看成是GPIO_ResetBits和GPIO_ResetBits 的结合体
	//最后一个参数可以是一个变量
//	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);	
	
	
	
	while(1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
		Delay_ms(1000);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
		Delay_ms(500);
	}
}
