/*
 * ultrasonic.h
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#ifndef APP_HW_DEVICE_INC_ULTRASONIC_H_
#define APP_HW_DEVICE_INC_ULTRASONIC_H_

#include "hw.h"

extern TIM_HandleTypeDef htim4;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HCSR04_US1_read();
void HCSR04_US2_read();
void HCSR04_US3_read();

#endif /* APP_HW_DEVICE_INC_ULTRASONIC_H_ */
