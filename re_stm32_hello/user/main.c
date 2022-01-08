
#include "stm32f4xx.h"
void init_led(){
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// 使能时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//初始化IO口
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIO
	
	
	//GPIO_SetBits(GPIOF,GPIO_Pin_9);
	
	
	
	//GPIO_SetBits(GPIOF,GPIO_Pin_10);
	//GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);//GPIOF9,F10设置高，灯灭
	
	GPIO_ResetBits(GPIOF,GPIO_Pin_10|GPIO_Pin_10); 
	
}
	


int main(){
	
	//*((int*)1000) = 100;
	init_led();
	
	//while(1);

	return 0;
}

