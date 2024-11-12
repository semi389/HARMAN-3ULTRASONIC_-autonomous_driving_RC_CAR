/*
 * motor.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#include "motor.h"

#define MOTOR_PIN_NAME GPIOC
#define MOTOR_LEFT_F GPIO_PIN_0
#define MOTOR_LEFT_B GPIO_PIN_1
#define MOTOR_RIGHT_F GPIO_PIN_2
#define MOTOR_RIGHT_B GPIO_PIN_3

extern uint16_t PWM_duty;

void Motor_Spin_F()
{
	PWM_Speed(PWM_duty);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 0);
}

void Motor_Spin_R()
{
	PWM_Speed(PWM_duty);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
}

void Motor_Spin_L()
{
	PWM_Speed(PWM_duty);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 0);
}

void Motor_Spin_Back()
{
	PWM_Speed(PWM_duty);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 0);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
}

void Motor_Spin_Stop()
{
	PWM_Speed(PWM_duty);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_LEFT_B, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_F, 1);
	HAL_GPIO_WritePin(MOTOR_PIN_NAME, MOTOR_RIGHT_B, 1);
}
