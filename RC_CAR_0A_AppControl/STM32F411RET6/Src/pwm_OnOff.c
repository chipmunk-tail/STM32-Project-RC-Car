/*
 * motorPWM.c
 *
 *  Created on: Jan 11, 2025
 *      Author: Dora
 */

#include "pwm_OnOff.h"



void pwmRun(uint16_t duty)
{
  TIM3->CCR1 = duty;
  TIM11->CCR1 = duty;
}
