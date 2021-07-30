
#include "stm32f4xx.h"                  // Device header
#include"delay.h"
#include"led.h"
#include"beep.h"
#include"key.h"

#define BEEP PFout(8)	// 蜂鸣器控制IO 

#define LED0 PFout(9)	// DS0
#define LED1 PFout(10)	// DS1

int main(){
	
	delay_init(168);
	led_init();
	beep_init();
	key_init();
	
	while(1){
		
		u8 key=key_scan(0); 	//得到键值
		
		if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//控制蜂鸣器
					BEEP=!BEEP;
					break;
				case KEY2_PRES:	//控制LED0翻转
					LED0=!LED0;
					break;
				case KEY1_PRES:	//控制LED1翻转	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
		
	}
	
	
	//return 0;
}

