#include "stm32f4xx.h"                  // Device header

#include"key.h"
#include"delay.h"

void key_init(){
	
	GPIO_InitTypeDef init;
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,ENABLE);
	
	//RCC->AHB1ENR|=1<<0;     //使能PORTA时钟 
	//RCC->AHB1ENR|=1<<4;     //使能PORTE时钟
	//GPIO_Set(GPIOE,PIN2|PIN3|PIN4,GPIO_MODE_IN,0,0,GPIO_PUPD_PU);	//PE2~4设置上拉输入
	//GPIO_Set(GPIOA,PIN0,GPIO_MODE_IN,0,0,GPIO_PUPD_PD); 			//PA0设置为下拉输入 
	
	init.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	init.GPIO_Mode = GPIO_Mode_IN;
	init.GPIO_Speed = GPIO_Speed_100MHz;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOE,&init);
	
	init.GPIO_Pin = GPIO_Pin_0;
	init.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	GPIO_Init(GPIOA,&init);
	
	
	
}


u8 key_scan(u8 mode){
	
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY0==0)return 1;
		else if(KEY1==0)return 2;
		else if(KEY2==0)return 3;
		else if(WK_UP==1)return 4;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
 	return 0;// 无按键按下
	
}



