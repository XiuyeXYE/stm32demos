
#include "stm32f4xx.h"                  // Device header
#include"delay.h"
#include"led.h"
#include"beep.h"


int main(){
	
	delay_init(168);
	led_init();
	beep_init();
	
	while(1){
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_8);
		delay_ms(500);
		
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_SetBits(GPIOF,GPIO_Pin_8);
		delay_ms(500);
		
	}
	
	
	//return 0;
}

