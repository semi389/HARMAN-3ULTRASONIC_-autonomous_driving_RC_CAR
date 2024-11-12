/*
 * ultrasonic.c
 *
 *  Created on: Nov 3, 2024
 *      Author: L1
 */
#include "ultrasonic.h"

extern uint16_t US1_VALUE1;
extern uint16_t US1_VALUE2;
extern uint16_t US1_echoTime;
extern uint8_t US1_captureFlag;
extern uint16_t US1_distance;

extern uint16_t US2_VALUE1;
extern uint16_t US2_VALUE2;
extern uint16_t US2_echoTime;
extern uint8_t US2_captureFlag;
extern uint16_t US2_distance;

extern uint16_t US3_VALUE1;
extern uint16_t US3_VALUE2;
extern uint16_t US3_echoTime;
extern uint8_t US3_captureFlag;
extern uint16_t US3_distance;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(US1_captureFlag == 0)
		{
			US1_VALUE1 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
			US1_captureFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(US1_captureFlag == 1)
		{
			US1_VALUE2 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);

			if(US1_VALUE2 > US1_VALUE1)
			{
				US1_echoTime = US1_VALUE2 - US1_VALUE1;
			}
			else if(US1_VALUE1 > US1_VALUE2)
			{
				US1_echoTime = (0xffff - US1_VALUE1) + US1_VALUE2;
			}
			US1_distance = US1_echoTime/58;
			US1_captureFlag = 0;

			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC1);
		}
	}

	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if(US2_captureFlag == 0)
		{
			US2_VALUE1 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_2);
			US2_captureFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(US2_captureFlag == 1)
		{
			US2_VALUE2 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_2);

			if(US2_VALUE2 > US2_VALUE1)
			{
				US2_echoTime = US2_VALUE2 - US2_VALUE1;
			}
			else if(US2_VALUE1 > US2_VALUE2)
			{
				US2_echoTime = (0xffff - US2_VALUE1) + US2_VALUE2;
			}
			US2_distance = US2_echoTime/58;
			US2_captureFlag = 0;

			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC2);
		}
	}

	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if(US3_captureFlag == 0)
		{
			US3_VALUE1 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_3);
			US3_captureFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(US3_captureFlag == 1)
		{
			US3_VALUE2 = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_3);

			if(US3_VALUE2 > US3_VALUE1)
			{
				US3_echoTime = US3_VALUE2 - US3_VALUE1;
			}
			else if(US3_VALUE1 > US3_VALUE2)
			{
				US3_echoTime = (0xffff - US3_VALUE1) + US3_VALUE2;
			}
			US3_distance = US3_echoTime/58;
			US3_captureFlag = 0;

			__HAL_TIM_SET_CAPTUREPOLARITY(&htim4, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim4, TIM_IT_CC3);
		}
	}
}

void HCSR04_US1_read()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
	delay_us(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC1);
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
}

void HCSR04_US2_read()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
	delay_us(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC2);
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_2);
}

void HCSR04_US3_read()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	delay_us(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);

	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC3);
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_3);
}

