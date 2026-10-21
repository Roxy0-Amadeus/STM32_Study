#include "stm32f10x.h"                  // Device header
#include <stdint.h>
#include "Delay.h"

volatile uint16_t CountSensor_Count = 0;
volatile uint8_t Sensor_Trigger_Flag = 0;

void CountSensor_Init(void)
{
	// 开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	// 配置 GPIO 上拉输入
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// 映射 EXTI14
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	
	// 配置 EXTI（下降沿触发，因为遮挡瞬间是下降沿）
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	// 配置 NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

uint8_t Get_Sensor_Flag(void)
{
	return Sensor_Trigger_Flag;
}

void Clear_Sensor_Flag(void)
{
	Sensor_Trigger_Flag = 0;
}

//计数器加一函数
void CountSensor_Increase(void)
{
	CountSensor_Count++;
}

//	中断服务函数
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET)
	{	
		Sensor_Trigger_Flag = 1;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
