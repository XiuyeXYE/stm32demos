#ifndef __PWM_H_
#define __PWM_H_

#include "sys.h"

#define LED0_PWM_VAL TIM14->CCR1    

void tim14_pwm_init(u16,u16);


#endif
