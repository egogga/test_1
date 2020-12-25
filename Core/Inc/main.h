/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32l4xx_hal.h"


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
void led(int8_t number, int8_t rank);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_g1_Pin GPIO_PIN_1
#define LED_g1_GPIO_Port GPIOA
#define LED_d1_Pin GPIO_PIN_2
#define LED_d1_GPIO_Port GPIOA
#define LED_c1_Pin GPIO_PIN_3
#define LED_c1_GPIO_Port GPIOA
#define LED_a1_Pin GPIO_PIN_4
#define LED_a1_GPIO_Port GPIOA
#define LED_b1_Pin GPIO_PIN_5
#define LED_b1_GPIO_Port GPIOA
#define LED_e2_Pin GPIO_PIN_6
#define LED_e2_GPIO_Port GPIOA
#define LED_d2_Pin GPIO_PIN_7
#define LED_d2_GPIO_Port GPIOA
#define LED_f2_Pin GPIO_PIN_0
#define LED_f2_GPIO_Port GPIOB
#define LED_g2_Pin GPIO_PIN_1
#define LED_g2_GPIO_Port GPIOB
#define LED_c2_Pin GPIO_PIN_10
#define LED_c2_GPIO_Port GPIOB
#define LED_a2_Pin GPIO_PIN_2
#define LED_a2_GPIO_Port GPIOB
#define LED_b2_Pin GPIO_PIN_11
#define LED_b2_GPIO_Port GPIOB
#define LED_Anode2_Pin GPIO_PIN_15
#define LED_Anode2_GPIO_Port GPIOB
#define LED_Anode1_Pin GPIO_PIN_8
#define LED_Anode1_GPIO_Port GPIOA
#define SensBut1_Pin GPIO_PIN_9
#define SensBut1_GPIO_Port GPIOA
#define SensBut2_Pin GPIO_PIN_10
#define SensBut2_GPIO_Port GPIOA
#define SensBut3_Pin GPIO_PIN_11
#define SensBut3_GPIO_Port GPIOA
#define Relay_Pin GPIO_PIN_15
#define Relay_GPIO_Port GPIOA
#define piezo_p_Pin GPIO_PIN_5
#define piezo_p_GPIO_Port GPIOB
#define LED_e1_Pin GPIO_PIN_8
#define LED_e1_GPIO_Port GPIOB
#define LED_f1_Pin GPIO_PIN_9
#define LED_f1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
