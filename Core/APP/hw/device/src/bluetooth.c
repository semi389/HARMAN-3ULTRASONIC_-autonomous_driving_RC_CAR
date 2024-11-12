/*
 * bluetooth.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#include "bluetooth.h"

#define MOTOR_PIN_NAME GPIOC
#define MOTOR_LEFT_F GPIO_PIN_0
#define MOTOR_LEFT_B GPIO_PIN_1
#define MOTOR_RIGHT_F GPIO_PIN_2
#define MOTOR_RIGHT_B GPIO_PIN_3

extern uint8_t Start;
extern uint8_t rxData;
extern uint16_t PWM_duty;

void Uart_rxData()
{
    HAL_UART_Receive_IT(&huart6, &rxData, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART6)
    {
        switch (rxData)
        {
            case '1':
          	  Start = 1;
                break;

            case '2':
          	  Start = 0;
          	  Motor_Spin_Stop();
                break;

            case '3':
          	  Start = 0;
          	  Motor_Spin_Stop();
                break;

         if(Start == 2)
         {
            case 'F':
            	PWM_Speed(PWM_duty);
				HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
				HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 0);
				HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
				HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 0);
            	break;

            case 'B':
            	PWM_Speed(PWM_duty);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 0);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 0);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
                break;

            case 'R':
            	PWM_Speed(PWM_duty);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 0);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 0);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
                break;

            case 'L':
            	PWM_Speed(PWM_duty);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 0);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 0);
                break;

            case 'S':
            	PWM_Speed(PWM_duty);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
            	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
                break;
         }
        }
        Uart_rxData();
    }
}
