#include"led.h"
#include<stm32f4xx.h>
#include"delay.h"

int main(){
	
	delay_init(168);
	

	led_init();
	
	
	while(1){
		
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		
		
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
		
		delay_ms(500);
		
	}
	
	
}

