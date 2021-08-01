
#include "stm32f4xx.h"                  // Device header
#include"delay.h"


void usart1_init(){
	
	GPIO_InitTypeDef init;
	USART_InitTypeDef usart_init;
	NVIC_InitTypeDef nvic_init;
	
	/**
	时钟和串口初始化，复用
	*/
	//时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	//复用引脚
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	
	//初始化A9 A10 引脚
	init.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	init.GPIO_Mode = GPIO_Mode_AF;
	init.GPIO_Speed = GPIO_Speed_50MHz;
	init.GPIO_OType = GPIO_OType_PP;
	init.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(GPIOA,&init);
	
	
	/**
	配置串口的寄存器，设置中断
	*/
	//串口初始化
	usart_init.USART_BaudRate = 115200;
	usart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart_init.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	usart_init.USART_Parity = USART_Parity_No;
	usart_init.USART_StopBits = USART_StopBits_1;
	usart_init.USART_WordLength = USART_WordLength_8b;	
	
	USART_Init(USART1,&usart_init);
	
	//串口使能
	USART_Cmd(USART1,ENABLE);
	
	//设置中断类型 接收非空，中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	//中断 初始化
	nvic_init.NVIC_IRQChannel = USART1_IRQn;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	nvic_init.NVIC_IRQChannelPreemptionPriority=1;
	nvic_init.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&nvic_init);
	
	
}

//中断函数
void USART1_IRQHandler(){
	
	u8 res;
	//判断接收中断
	if(USART_GetITStatus(USART1,USART_IT_RXNE)){
		res = USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
	
}


int main(){
	
	//配置中断分组，相当于配置全局中断类型
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	usart1_init();
	
	while(1);
}

