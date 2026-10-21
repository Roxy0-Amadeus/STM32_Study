#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "CountSensor.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//配置总体的中断优先级分组
	
	OLED_Init();
	CountSensor_Init();
	
	OLED_ShowString(1, 1, "Antonio");
	OLED_ShowString(1, 10, "Amadeus");
	OLED_ShowString(2, 3, "Count:");
	
	while(1)
	{
		if(Get_Sensor_Flag() == 1)
		{	
			Delay_ms(10);
				
			if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
			{
				CountSensor_Increase();
			
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
			}
			Clear_Sensor_Flag();
		}
		
		//随时刷新屏幕
		 OLED_ShowNum(2, 10, CountSensor_Get(),5);
	}
}
