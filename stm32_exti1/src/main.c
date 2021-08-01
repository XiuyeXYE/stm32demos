
#include "stm32f4xx.h"                  // Device header
#include "delay.h"
#include "exti.h"

#include "led.h"
#include "beep.h"





int main(){
	
	//配置中断分组，相当于配置全局中断类型
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init(168);    //初始化延时函数
	
	led_init();
	beep_init();
	
	
	extix_Init();
	
	LED0 = 0;
	
	while(1);
}

