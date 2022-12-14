/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define Btn1_Pin GPIO_PIN_2
#define Btn1_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_3
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_4
#define EN1_GPIO_Port GPIOA
#define Btn2_Pin GPIO_PIN_5
#define Btn2_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_6
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_7
#define EN3_GPIO_Port GPIOA
#define A_7SEG_Pin GPIO_PIN_0
#define A_7SEG_GPIO_Port GPIOB
#define B_7SEG_Pin GPIO_PIN_1
#define B_7SEG_GPIO_Port GPIOB
#define C_7SEG_Pin GPIO_PIN_2
#define C_7SEG_GPIO_Port GPIOB
#define Btn3_Pin GPIO_PIN_8
#define Btn3_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_9
#define LED_RED_GPIO_Port GPIOA
#define LED_RED1_Pin GPIO_PIN_10
#define LED_RED1_GPIO_Port GPIOA
#define LED_AMBER_Pin GPIO_PIN_11
#define LED_AMBER_GPIO_Port GPIOA
#define LED_AMBER1_Pin GPIO_PIN_12
#define LED_AMBER1_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_13
#define LED_GREEN_GPIO_Port GPIOA
#define LED_GREEN1_Pin GPIO_PIN_14
#define LED_GREEN1_GPIO_Port GPIOA
#define D_7SEG_Pin GPIO_PIN_3
#define D_7SEG_GPIO_Port GPIOB
#define E_7SEG_Pin GPIO_PIN_4
#define E_7SEG_GPIO_Port GPIOB
#define F_7SEG_Pin GPIO_PIN_5
#define F_7SEG_GPIO_Port GPIOB
#define G_7SEG_Pin GPIO_PIN_6
#define G_7SEG_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
