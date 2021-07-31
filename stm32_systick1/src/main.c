
#include "stm32f4xx.h"                  // Device header
#include"delay.h"
#include"led.h"
#include"beep.h"
#include"key.h"


#define BEEP PFout(8)	// 蜂鸣器控制IO 

#define LED0 PFout(9)	// DS0
#define LED1 PFout(10)	// DS1

static __IO u32 time;

void delay(__IO u32 ms){
	time = ms;
	while(time > 0);
}

void SysTick_Handler(){
	if(time > 0){
		time --;
	}
}

int main(){
	
	
	led_init();
	beep_init();
	
	//每秒168M
	//每一毫秒 168M/1000
	SysTick_Config(SystemCoreClock/1000);
	
	BEEP = 0;
	LED0 = 0;
	LED1 = 0;
	
	while(1){
		
		delay(500);
		
		BEEP = !BEEP;
		LED0 = !LED0;
		LED1 = !LED1;
		
	}
	
	
	//return 0;
}

