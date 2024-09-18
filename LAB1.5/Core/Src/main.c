/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  void display7SEG(int num, uint32_t GPIO_PIN) {
        char segNum[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
        //char state = segNum[num];
        for (int i = 0; i < 7; ++i) {
        	HAL_GPIO_WritePin(GPIOB, GPIO_PIN << i, (segNum[num] >> i) & 1);
        }
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 0, (state >> 0) & 1); // Segment A
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 1, (state >> 1) & 1); // Segment B
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 2, (state >> 2) & 1); // Segment C
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 3, (state >> 3) & 1); // Segment D
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 4, (state >> 4) & 1); // Segment E
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 5, (state >> 5) & 1); // Segment F
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN << 6, (state >> 6) & 1); // Segment G
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (state & 0x01) ? SET : RESET); // Segment A1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (state & 0x02) ? SET : RESET); // Segment B1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (state & 0x04) ? SET : RESET); // Segment C1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (state & 0x08) ? SET : RESET); // Segment D1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (state & 0x10) ? SET : RESET); // Segment E1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (state & 0x20) ? SET : RESET); // Segment F1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (state & 0x40) ? SET : RESET); // Segment G1
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, (state & 0x01) ? SET : RESET); // Segment A2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (state & 0x02) ? SET : RESET); // Segment B2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (state & 0x04) ? SET : RESET); // Segment C2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (state & 0x08) ? SET : RESET); // Segment D2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (state & 0x10) ? SET : RESET); // Segment E2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (state & 0x20) ? SET : RESET); // Segment F2
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (state & 0x40) ? SET : RESET); // Segment G2
  }

  int red = 5, yellow = 2, green = 3;
  int direct = 1;
  while (1) {
        if(direct == 1) {
        	if (red > 0) {
        		display7SEG(red, GPIO_PIN_7);
				if(red >= 3) {
					HAL_GPIO_WritePin(GPIOA, S1_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S3_Pin, SET);

					HAL_GPIO_WritePin(GPIOA, S4_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S5_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S6_Pin, RESET);

					display7SEG(green, GPIO_PIN_0);
					green--;
				}
				if (red >= 1 && red < 3) {
					HAL_GPIO_WritePin(GPIOA, S1_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S3_Pin, SET);

					HAL_GPIO_WritePin(GPIOA, S4_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S5_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S6_Pin, SET);
					display7SEG(yellow, GPIO_PIN_0);
					yellow--;
        		}
        	red--;
        	}
        	if(yellow == 0) yellow = 2;
        	if(green == 0) green = 3;
        	if(red == 0) {
        		red += 5;
            	direct = 0;
        	}
        }
        else {
        	if (red > 0) {
				display7SEG(red, GPIO_PIN_0);
				if(red >= 3) {
					HAL_GPIO_WritePin(GPIOA, S4_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S5_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S6_Pin, SET);

					HAL_GPIO_WritePin(GPIOA, S1_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S3_Pin, RESET);

					display7SEG(green, GPIO_PIN_7);
					green--;
				}
				if (red >= 1 && red < 3) {
					HAL_GPIO_WritePin(GPIOA, S4_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S5_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S6_Pin, SET);

					HAL_GPIO_WritePin(GPIOA, S1_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, S2_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, S3_Pin, SET);
					display7SEG(yellow, GPIO_PIN_7);
					yellow--;
				}
			red--;
        	}
			if(yellow == 0) yellow = 2;
			if(green == 0) green = 3;
			if(red == 0) {
				red += 5;
				direct = 1;
			}
        }
        HAL_Delay(1000);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  HAL_GPIO_WritePin(GPIOA, S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D2_Pin
                          |E2_Pin|F2_Pin|G2_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|A2_Pin
                          |B2_Pin|C2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : S1_Pin S2_Pin S3_Pin S4_Pin
                           S5_Pin S6_Pin */
  GPIO_InitStruct.Pin = S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A1_Pin B1_Pin C1_Pin D2_Pin
                           E2_Pin F2_Pin G2_Pin D1_Pin
                           E1_Pin F1_Pin G1_Pin A2_Pin
                           B2_Pin C2_Pin */
  GPIO_InitStruct.Pin = A1_Pin|B1_Pin|C1_Pin|D2_Pin
                          |E2_Pin|F2_Pin|G2_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|A2_Pin
                          |B2_Pin|C2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
