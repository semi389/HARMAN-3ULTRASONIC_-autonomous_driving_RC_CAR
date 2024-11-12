/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Motor_L_Front_Pin GPIO_PIN_0
#define Motor_L_Front_GPIO_Port GPIOC
#define Motor_L_Back_Pin GPIO_PIN_1
#define Motor_L_Back_GPIO_Port GPIOC
#define Motor_R_Front_Pin GPIO_PIN_2
#define Motor_R_Front_GPIO_Port GPIOC
#define Motor_R_Back_Pin GPIO_PIN_3
#define Motor_R_Back_GPIO_Port GPIOC
#define Motor_CH1_Pin GPIO_PIN_6
#define Motor_CH1_GPIO_Port GPIOA
#define Motor_CH2_Pin GPIO_PIN_7
#define Motor_CH2_GPIO_Port GPIOA
#define Bluetooth_TX_Pin GPIO_PIN_6
#define Bluetooth_TX_GPIO_Port GPIOC
#define Bluetooth_RX_Pin GPIO_PIN_7
#define Bluetooth_RX_GPIO_Port GPIOC
#define US1_tr_Pin GPIO_PIN_3
#define US1_tr_GPIO_Port GPIOB
#define US2_tr_Pin GPIO_PIN_4
#define US2_tr_GPIO_Port GPIOB
#define US2_trB5_Pin GPIO_PIN_5
#define US2_trB5_GPIO_Port GPIOB
#define US1_Ec_Pin GPIO_PIN_6
#define US1_Ec_GPIO_Port GPIOB
#define US2_Ec_Pin GPIO_PIN_7
#define US2_Ec_GPIO_Port GPIOB
#define US3_Ec_Pin GPIO_PIN_8
#define US3_Ec_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
