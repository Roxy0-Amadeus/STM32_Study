#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "SERVO.h"

int main(void)
{
	OLED_Init();
	Servo_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	
	while(1)
	{
		Servo_SetAngle(0);
        Delay_ms(1000);
        
        Servo_SetAngle(90);
        Delay_ms(1000);
        
        Servo_SetAngle(180);
        Delay_ms(1000);
	}
}
