
#include "stm32f4xx.h"                  // Device header
#include "delay.h"
//#include "exti.h"
#include "led.h"
//#include "beep.h"
//#include "iwdog.h"
#include "key.h"
//#include "wwdog.h"
//#include "timer.h"

#include "pwm.h"





int main(){
	
	u16 led0pwmval=0;    
	u8 dir=1;
	
	//配置中断分组，相当于配置全局中断类型
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init(168);    //初始化延时函数
	
	led_init();
	//beep_init();
	
	//tim3_init(4999,8399);
	
	//iwdg_init(4,500);
	
	//extix_Init();
	
	
	tim14_pwm_init(500-1,84-1);
	
	
	
	while(1){
		
		delay_ms(10);	 
		if(dir)led0pwmval++;
		else led0pwmval--;	 
 		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;	   					 
		LED0_PWM_VAL=led0pwmval;	
		
		
	}
}

