#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#define max 180

void Servo_Init(void)
{
	PWM_Init();
}

static uint8_t Clamp( uint8_t value, uint8_t Max)
{
	if(value > Max) return Max;
	return value;
}
void Servo_SetAngle(uint8_t Angle)
{
	uint8_t Clamp_val = Clamp(Angle, max);
	uint16_t compare_val = 500 + (Clamp_val * 100) / 9;
	
	PWM_SetCompare1(compare_val);
}
