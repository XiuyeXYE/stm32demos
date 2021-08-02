
#include "timer.h"
#include "led.h"

void tim3_init(u16 arr,u16 psc){
	
	TIM_TimeBaseInitTypeDef tim_init;
	NVIC_InitTypeDef nvic_init;
	
	//使能时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	
	tim_init.TIM_Period = arr;
	tim_init.TIM_Prescaler = psc;
	tim_init.TIM_CounterMode = TIM_CounterMode_Up;
	tim_init.TIM_ClockDivision = TIM_CKD_DIV1;
	
	//初始化时钟
	TIM_TimeBaseInit(TIM3,&tim_init);
	
	//设置中断
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	//初始化中断
	nvic_init.NVIC_IRQChannel=TIM3_IRQn;//定时器3中断
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	nvic_init.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级
	nvic_init.NVIC_IRQChannelSubPriority=3;//响应优先级
	
	NVIC_Init(&nvic_init);
	
	//中断开启
	TIM_Cmd(TIM3,ENABLE);
	
	
}

void TIM3_IRQHandler(){
	
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET){
		
		LED1 = !LED1;
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		
	}
	
	
}


