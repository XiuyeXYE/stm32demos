#include"led.h"
#include<stm32f4xx.h>

void led_init(){
	
	//使能时钟
	RCC->AHB1ENR |= 1<<5;
	
	//f9
	//相应的位 代表 io口
	GPIOF->MODER &= ~(3<<2*9) ;
	GPIOF->MODER |= 1<<(2*9);
	
	GPIOF->OSPEEDR &= ~(3<<2*9) ;
	GPIOF->OSPEEDR |= 2<<2*9;
	
	GPIOF->PUPDR &= ~(3<<2*9) ;
	GPIOF->PUPDR |= 1<<(2*9);
	
	GPIOF->OTYPER &= ~(1<<9) ;
	GPIOF->OTYPER |= 0<<9;
	
	GPIOF->ODR |= 1<<9;
	//GPIOF->ODR &= ~(1<<9);
	
	//f10
	GPIOF->MODER &= ~(3<<2*10) ;
	GPIOF->MODER |= 1<<(2*10);
	
	GPIOF->OSPEEDR &= ~(3<<2*10) ;
	GPIOF->OSPEEDR |= 2<<2*10;
	
	GPIOF->PUPDR &= ~(3<<2*10) ;
	GPIOF->PUPDR |= 1<<(2*10);
	
	GPIOF->OTYPER &= ~(1<<10) ;
	GPIOF->OTYPER |= 0<<10;
	
	GPIOF->ODR |= 1<<10;
	
	
	
}
