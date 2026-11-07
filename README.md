# STM32 学习工程归档

本仓库用于记录基于 STM32F103C8T6 和标准外设库（SPL）的学习历程。

## 工程目录
* `00_Template` -基础模板
* `01_LED_Blink` - GPIO 点灯基础测试
* `02_LED_Flow` - GPIO 流水灯控制
* `03_Buzzer` - 蜂鸣器控制
* `04_Key_Control` - 按键轮询控制 LED
* `05_Light_Sensor` - 光敏电阻控制蜂鸣器
* `06_OLED_Display` - 引入 OLED 驱动库实现基础显示
* `07_IR_Counting` - 对射式红外传感器 EXTI 中断计次
* `08_Rotary_Encoder` - 旋转编码器计次（开发中）
* `09_TIM_Base_Interrupt` - TIM 基础定时器中断闪灯
* `10_TIM_ExternalClock` - TIM 外部时钟模式与红外对射计数
* `11_PWM_LED_Breath` - TIM 输出比较与 PWM 呼吸灯调制
* `12_PWM_Key_Control` - 基于按键控制的 PWM 动态调光

## 开发环境
* 芯片：STM32F103C8T6
* 编译器：Keil MDK (ARM Compiler 5)
* 库：STM32F10x Standard Peripheral Library

## 学习进度
- [x] GPIO 输入输出
- [x] EXTI 外部中断
- [x] TIM 定时器 (中断、外部时钟、PWM)
- [ ] USART 串口通信
- [ ] ADC 模数转换
- [ ] I2C / SPI 通信