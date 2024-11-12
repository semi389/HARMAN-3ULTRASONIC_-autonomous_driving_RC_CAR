/*
 * bluetooth.h
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#ifndef APP_HW_DEVICE_INC_BLUETOOTH_H_
#define APP_HW_DEVICE_INC_BLUETOOTH_H_

#include "hw.h"

extern UART_HandleTypeDef huart6;

void Uart_rxData();
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* APP_HW_DEVICE_INC_BLUETOOTH_H_ */
