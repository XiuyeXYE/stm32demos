#include"led.h"
#include<stm32f4xx.h>

void led_init(){
	
	GPIO_InitTypeDef init;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//F9
	init.GPIO_Pin = GPIO_Pin_9;
	init.GPIO_Mode = GPIO_Mode_OUT;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	init.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOF,&init);
	GPIO_SetBits(GPIOF,GPIO_Pin_9);
	
	//F10
	init.GPIO_Pin = GPIO_Pin_10;
	init.GPIO_Mode = GPIO_Mode_OUT;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	init.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOF,&init);
	GPIO_SetBits(GPIOF,GPIO_Pin_10);
	
	
}
