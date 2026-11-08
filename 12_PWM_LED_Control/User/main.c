#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"

#define DUTY_STEP 10
#define DUTY_MAX  100

uint8_t pwm_duty = 0;

uint8_t Duty_Update(uint8_t current_duty)
{
	current_duty += DUTY_STEP;
		if(current_duty > DUTY_MAX)
		{
			current_duty = 0;
		}
		return current_duty;
}
	
int main(void)
{
	OLED_Init();
	PWM_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowNum(2, 1, pwm_duty, 3);
	
	PWM_SetCompare1(pwm_duty);
	
	while(1)
	{
		if(Key_GetNum() == 1)
		{	
			pwm_duty = Duty_Update(pwm_duty);
			PWM_SetCompare1(pwm_duty);
			OLED_ShowNum(2, 1, pwm_duty, 3);
		}
	}
}
