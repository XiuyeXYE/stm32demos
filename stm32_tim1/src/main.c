
#include "stm32f4xx.h"                  // Device header
#include "delay.h"
//#include "exti.h"
#include "led.h"
//#include "beep.h"
//#include "iwdog.h"
#include "key.h"
//#include "wwdog.h"
#include "timer.h"




int main(){
	
	//配置中断分组，相当于配置全局中断类型
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init(168);    //初始化延时函数
	
	led_init();
	//beep_init();
	
	tim3_init(4999,8399);
	
	//iwdg_init(4,500);
	
	//extix_Init();
	
	
	//LED1 = 0;
	
	
	//LED0 = 0;
	//delay_ms(500);
	//WWDG_Init(0x7F,0x5F,WWDG_Prescaler_8);//计数器值为7f,窗口寄存器为5f,分频数为8	
	
	while(1){
		
		LED0 = !LED0;
		
		delay_ms(200);
		
		//防止独立看门狗复位系统，不同按wake_up按键
		//if(key_scan(0) == WKUP_PRES){
		//	IWDG_ReloadCounter();
		//}
		
		//delay_ms(10);
		
		//LED0 = 1;
		
		
	}
}

