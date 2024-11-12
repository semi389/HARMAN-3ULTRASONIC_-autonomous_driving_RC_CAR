/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ap.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern uint8_t Start;
extern uint8_t rxData;

extern uint16_t US1_distance;
extern uint16_t US2_distance;
extern uint16_t US3_distance;
/* USER CODE END Variables */
/* Definitions for US1 */
osThreadId_t US1Handle;
const osThreadAttr_t US1_attributes = {
  .name = "US1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for US2 */
osThreadId_t US2Handle;
const osThreadAttr_t US2_attributes = {
  .name = "US2",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for US3 */
osThreadId_t US3Handle;
const osThreadAttr_t US3_attributes = {
  .name = "US3",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Motor */
osThreadId_t MotorHandle;
const osThreadAttr_t Motor_attributes = {
  .name = "Motor",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void US1T(void *argument);
void US2T(void *argument);
void US3T(void *argument);
void MotorS(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of US1 */
  US1Handle = osThreadNew(US1T, NULL, &US1_attributes);

  /* creation of US2 */
  US2Handle = osThreadNew(US2T, NULL, &US2_attributes);

  /* creation of US3 */
  US3Handle = osThreadNew(US3T, NULL, &US3_attributes);

  /* creation of Motor */
  MotorHandle = osThreadNew(MotorS, NULL, &Motor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_US1T */
/**
  * @brief  Function implementing the US1 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_US1T */
void US1T(void *argument)
{
  /* USER CODE BEGIN US1T */
  /* Infinite loop */
  for(;;)
  {
	  if (Start == 1)
	  {
		HCSR04_US1_read();
		osDelay(50);
	  }
  }
  /* USER CODE END US1T */
}

/* USER CODE BEGIN Header_US2T */
/**
* @brief Function implementing the US2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_US2T */
void US2T(void *argument)
{
  /* USER CODE BEGIN US2T */
  /* Infinite loop */
  for(;;)
  {
	  if (Start == 1)
	  {
		HCSR04_US2_read();
		osDelay(50);
	  }
  }
  /* USER CODE END US2T */
}

/* USER CODE BEGIN Header_US3T */
/**
* @brief Function implementing the US3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_US3T */
void US3T(void *argument)
{
  /* USER CODE BEGIN US3T */
  /* Infinite loop */
  for(;;)
  {
	  if (Start == 1)
	  {
		HCSR04_US3_read();
		osDelay(50);
	  }
  }
  /* USER CODE END US3T */
}

/* USER CODE BEGIN Header_MotorS */
/**
* @brief Function implementing the Motor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MotorS */
void MotorS(void *argument)
{
  /* USER CODE BEGIN MotorS */
  /* Infinite loop */
  for(;;)
  {
	  if (Start == 1)
	  {
		  if (US2_distance > 30)
		  {
			  Motor_Spin_F();

			  if (US1_distance > 20 && US3_distance <= 20)
			  {
				  Motor_Spin_L();
			  }
			  if (US3_distance > 20 && US1_distance <= 20)
			  {
				  Motor_Spin_R();
			  }
		  }

		  if (US2_distance < 20)
		  {
			  if (US1_distance > 13 && US3_distance <= 13)
			  {
				  Motor_Spin_L();
				  delay_100us(500);
			  }
			  if (US3_distance > 13 && US1_distance <= 13)
			  {
				  Motor_Spin_R();
				  delay_100us(500);
			  }
		  }

		  if (US2_distance < 10)
		  {
			  if (US1_distance > 8 && US3_distance <= 8)
			  {
				  Motor_Spin_Back();
				  delay_100us(2000);
				  Motor_Spin_L();
				  delay_100us(1000);
			  }
			  if (US3_distance > 8 && US1_distance <= 8)
			  {
				  Motor_Spin_Back();
				  delay_100us(2000);
				  Motor_Spin_R();
				  delay_100us(1000);
			  }
		  }

		  if (US2_distance < 7)
		  {
			  if (US1_distance > US3_distance)
			  {
				  Motor_Spin_Back();
				  delay_100us(3000);
				  Motor_Spin_L();
				  delay_100us(1500);
			  }
			  if (US3_distance > US1_distance)
			  {
				  Motor_Spin_Back();
				  delay_100us(3000);
				  Motor_Spin_R();
				  delay_100us(1500);
			  }
		  }
	  }
    osDelay(5);
  }
  /* USER CODE END MotorS */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

