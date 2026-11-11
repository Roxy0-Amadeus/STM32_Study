#include "stm32f10x.h"                  // Device header
#include "PWM.h"

#define MAX_SPEED 50
#define MIN_SPEED -50
#define SPEED_STEP 10

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor_SetSpeed(int16_t Speed)
{	
	if(Speed > 100) Speed = 100;
	if(Speed < -100) Speed = -100;
	
	if(Speed >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		PWM_SetCompare1(Speed);
	}
	else
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare1(-Speed);
	}
}

int16_t Motor_GetNextSpeed(void)
{
	static int16_t speed = 0;
	static int8_t step = SPEED_STEP;
	
	speed += step;
	
	if(speed > MAX_SPEED)
	{
		step = -SPEED_STEP ;
		speed = MAX_SPEED + step;
	}
	else if(speed < MIN_SPEED)
	{
		step = SPEED_STEP ;
		speed = MIN_SPEED + step;
	}
	
	return speed;
}
