/*
 * ap.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */

#include "ap.h"

uint8_t Start = 0;
uint8_t rxData;

uint16_t US1_VALUE1 = 0;
uint16_t US1_VALUE2 = 0;
uint16_t US1_echoTime = 0;
uint8_t US1_captureFlag = 0;
uint16_t US1_distance = 0;

uint16_t US2_VALUE1 = 0;
uint16_t US2_VALUE2 = 0;
uint16_t US2_echoTime = 0;
uint8_t US2_captureFlag = 0;
uint16_t US2_distance = 0;

uint16_t US3_VALUE1 = 0;
uint16_t US3_VALUE2 = 0;
uint16_t US3_echoTime = 0;
uint8_t US3_captureFlag = 0;
uint16_t US3_distance = 0;

uint16_t PWM_duty = 450;

void apInit()
{
	  HAL_TIM_Base_Start(&htim9);
}

void apMain()
{
	  PWM_Init();
	  Uart_rxData();

	while (1)
	{

	}
}
