/*
 * motorPWM.c
 *
 *  Created on: Jan 11, 2025
 *      Author: Dora
 */

#include "pwm_OnOff.h"



void pwmRunR(uint16_t duty)
{
  TIM11->CCR1 = duty;
}


void pwmRunL(uint16_t duty)
{
  TIM3->CCR1 = duty;
}
