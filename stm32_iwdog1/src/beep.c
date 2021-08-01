
#include "stm32f4xx.h"                  // Device header

#include"beep.h"

void beep_init(){
	
	GPIO_InitTypeDef init;
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	
	
	init.GPIO_Pin = GPIO_Pin_8;
	init.GPIO_Mode = GPIO_Mode_OUT;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_Speed = GPIO_Speed_25MHz;
	init.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	GPIO_Init(GPIOF,&init);
	
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);
	
	
}

