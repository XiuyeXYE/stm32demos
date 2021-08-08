
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

#include "tim5_input.h"

#include "usart.h"	



extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u32	TIM5CH1_CAPTURE_VAL;	//输入捕获值  



int main(){
	
	//u16 led0pwmval=0;    
	//u8 dir=1;
	long long temp=0;  
	
	//配置中断分组，相当于配置全局中断类型
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init(168);    //初始化延时函数
	uart_init(84,115200);		//初始化串口波特率为115200
	led_init();
	//beep_init();
	
	//tim3_init(4999,8399);
	
	//iwdg_init(4,500);
	
	//extix_Init();
	
	
	tim14_pwm_init(500-1,84-1);
	
	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1);//以1Mhz的频率计数 
	
	
	while(1){
		
		//delay_ms(10);	 
		//if(dir)led0pwmval++;
		//else led0pwmval--;	 
 		//if(led0pwmval>300)dir=0;
		//if(led0pwmval==0)dir=1;	   					 
		//LED0_PWM_VAL=led0pwmval;	
		delay_ms(10);
		LED0_PWM_VAL++;
		if(LED0_PWM_VAL==300)LED0_PWM_VAL=0;	 		 
 		if(TIM5CH1_CAPTURE_STA&0X80)//成功捕获到了一次高电平
		{
			temp=TIM5CH1_CAPTURE_STA&0X3F; 
			temp*=0XFFFFFFFF;		 		//溢出时间总和
			temp+=TIM5CH1_CAPTURE_VAL;		//得到总的高电平时间
			printf("HIGH:%lld us\r\n",temp);//打印总的高点平时间
			TIM5CH1_CAPTURE_STA=0;			//开启下一次捕获
		}
		
	}
}

