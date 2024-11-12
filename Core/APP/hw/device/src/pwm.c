/*
 * pwm.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#include "pwm.h"

void PWM_Init(void)
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void PWM_Speed(uint16_t CCR)
{
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, CCR);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, CCR);
}
