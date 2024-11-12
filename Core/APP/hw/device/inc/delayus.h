/*
 * delayus.h
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#ifndef APP_HW_DEVICE_INC_DELAYUS_H_
#define APP_HW_DEVICE_INC_DELAYUS_H_

#include "hw.h"

extern TIM_HandleTypeDef htim9;

void delay_100us(uint32_t us100);
void delay_us(uint16_t us);

#endif /* APP_HW_DEVICE_INC_DELAYUS_H_ */
