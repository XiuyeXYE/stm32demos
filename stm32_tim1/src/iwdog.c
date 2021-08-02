


#include "iwdog.h"

void iwdg_init(u8 prer,u16 rlr){
	
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prer);
	IWDG_SetReload(rlr);
	//喂狗
	IWDG_ReloadCounter();
	
	IWDG_Enable();
	
	
}






