/*
 * pwm.h
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#ifndef APP_HW_DEVICE_INC_PWM_H_
#define APP_HW_DEVICE_INC_PWM_H_

#include "hw.h"

extern TIM_HandleTypeDef htim3;

void PWM_Init(void);
void PWM_Speed(uint16_t CCR);

#endif /* APP_HW_DEVICE_INC_PWM_H_ */
