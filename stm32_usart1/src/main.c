
#include "stm32f4xx.h"                  // Device header
#include"delay.h"



int main(){
	
	
	GPIO_InitTypeDef init;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	
	init.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	init.GPIO_Mode = GPIO_Mode_AF;
	init.GPIO_Speed = GPIO_Speed_50MHz;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOA,&init);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	
	

	
	//while(1){
		
		
		
	//}
	
	
	return 0;
}

