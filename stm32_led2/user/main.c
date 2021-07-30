#include"led.h"
#include<stm32f4xx.h>
#include"delay.h"

int main(){
	
	delay_init(168);
	

	led_init();
	
	
	while(1){
		
		GPIOF->ODR &= ~(1<<9);
		GPIOF->ODR &= ~(1<<10);
		delay_ms(500);
		
		
		GPIOF->ODR |= 1<<9;
		GPIOF->ODR |= 1<<10;
		delay_ms(500);
		
	}
	
	
}

