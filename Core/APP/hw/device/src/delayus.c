/*
 * delayus.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#include "delayus.h"

void delay_100us(uint32_t us100)
{
	__HAL_TIM_SET_COUNTER(&htim9, 0);
	while((__HAL_TIM_GET_COUNTER(&htim9)) < us100);
}

void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim9, 0);
	while((__HAL_TIM_GET_COUNTER(&htim9)) < us);
}
