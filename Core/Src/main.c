//Тест для гитхаба 1

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t SensButton1,SensButton2,SensButton3,Button1wasPressed,Button2wasPressed,ToggleVar1;
int i,j;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  //HAL_GPIO_WritePin(Relay_GPIO_Port,Relay_Pin, 1);
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(LED_Anode1_GPIO_Port,LED_Anode1_Pin,0);
  HAL_GPIO_WritePin(LED_Anode2_GPIO_Port,LED_Anode2_Pin,0);
  i=0;
  j=0;
  Button1wasPressed=0;
  Button2wasPressed=0;
  ToggleVar1=0;

  while (1)
  {
    /* USER CODE END WHILE */
	  if(i>=2) HAL_GPIO_WritePin(Relay_GPIO_Port,Relay_Pin,1); //переключение рэле
	  else HAL_GPIO_WritePin(Relay_GPIO_Port,Relay_Pin,0);


	  if(i>=0)
	  {
		  SensButton3 = HAL_GPIO_ReadPin(SensBut3_GPIO_Port, SensBut3_Pin);
		  if(SensButton3 == 1)
			 {
				  led(i,1);
				  led(j,2);
				  j++;
			 }

		  SensButton2 = HAL_GPIO_ReadPin(SensBut2_GPIO_Port, SensBut2_Pin);
		  if(SensButton2 == 1)
			 {
				  led(i,1);
				  led(j,2);
				  j--;
			 }

		  if(j>9)   //Для счета десятков
		  {
			  i++;
			  j=0;
		  }
		  else if(j<0)
		  {
			  i--;
			  j=9;
		  }

	  }
	  else
	  {
		  i=0;
		  j=0;

	  }







	  SensButton1 = HAL_GPIO_ReadPin(SensBut1_GPIO_Port, SensBut1_Pin);
	  if(SensButton1 == 1)
		  {
			HAL_GPIO_TogglePin(LED_Anode1_GPIO_Port,LED_Anode1_Pin);
			HAL_GPIO_TogglePin(LED_Anode2_GPIO_Port,LED_Anode2_Pin);
		  }

	  HAL_Delay(300);


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_g1_Pin|LED_d1_Pin|LED_c1_Pin|LED_a1_Pin 
                          |LED_b1_Pin|LED_e2_Pin|LED_d2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_f2_Pin|LED_g2_Pin|LED_c2_Pin|LED_b2_Pin 
                          |LED_e1_Pin|LED_f1_Pin|LED_a2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|LED_Anode2_Pin|piezo_p_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_Anode1_Pin|Relay_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_g1_Pin LED_d1_Pin LED_c1_Pin LED_a1_Pin 
                           LED_b1_Pin LED_e2_Pin LED_d2_Pin LED_Anode1_Pin 
                           Relay_Pin */
  GPIO_InitStruct.Pin = LED_g1_Pin|LED_d1_Pin|LED_c1_Pin|LED_a1_Pin 
                          |LED_b1_Pin|LED_e2_Pin|LED_d2_Pin|LED_Anode1_Pin 
                          |Relay_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_f2_Pin LED_g2_Pin PB2 LED_c2_Pin 
                           LED_b2_Pin LED_Anode2_Pin piezo_p_Pin LED_e1_Pin 
                           LED_f1_Pin */
  GPIO_InitStruct.Pin = LED_f2_Pin|LED_g2_Pin|GPIO_PIN_2|LED_c2_Pin 
                          |LED_b2_Pin|LED_Anode2_Pin|piezo_p_Pin|LED_e1_Pin 
                          |LED_f1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : SensBut1_Pin SensBut2_Pin SensBut3_Pin */
  GPIO_InitStruct.Pin = SensBut1_Pin|SensBut2_Pin|SensBut3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
