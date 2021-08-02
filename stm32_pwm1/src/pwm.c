
#include "pwm.h"


//TIM14 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void tim14_pwm_init(u16 arr,u16 psc){
	
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<8; 	//TIM14时钟使能    
	RCC->AHB1ENR|=1<<5;   	//使能PORTF时钟	
	GPIO_Set(GPIOF,PIN9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOF,9,9);	//PF9,AF9 
	
	TIM14->ARR=arr;			//设定计数器自动重装值 
	TIM14->PSC=psc;			//预分频器不分频 
	TIM14->CCMR1|=6<<4;  	//CH1 PWM1模式		 
	TIM14->CCMR1|=1<<3; 	//CH1 预装载使能	   
	TIM14->CCER|=1<<0;   	//OC1 输出使能	
	TIM14->CCER|=1<<1;   	//OC1 低电平有效	   
	TIM14->CR1|=1<<7;   	//ARPE使能 
	TIM14->CR1|=1<<0;    	//使能定时器14 		
	
}



