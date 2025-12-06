/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32wbxx_hal.h"

#include "app_conf.h"
#include "app_entry.h"
#include "app_common.h"

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
void set_flag(volatile uint32_t *flag_variable, uint32_t flag);
void clear_flag(volatile uint32_t *flag_variable, uint32_t flag);
uint32_t read_flag(uint32_t *flag_variable, uint32_t flag);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DISPL_LED_Pin GPIO_PIN_0
#define DISPL_LED_GPIO_Port GPIOA
#define TEST_Pin GPIO_PIN_1
#define TEST_GPIO_Port GPIOA
#define DISPL_RST_Pin GPIO_PIN_4
#define DISPL_RST_GPIO_Port GPIOA
#define DISPL_CS_Pin GPIO_PIN_8
#define DISPL_CS_GPIO_Port GPIOA
#define DISPL_DC_Pin GPIO_PIN_9
#define DISPL_DC_GPIO_Port GPIOA
#define TOUCH_CS_Pin GPIO_PIN_2
#define TOUCH_CS_GPIO_Port GPIOB
#define SEL_KEY_Pin GPIO_PIN_0
#define SEL_KEY_GPIO_Port GPIOB
#define SEL_KEY_EXTI_IRQn EXTI0_IRQn
#define SET_KEY_Pin GPIO_PIN_1
#define SET_KEY_GPIO_Port GPIOB
#define SET_KEY_EXTI_IRQn EXTI1_IRQn
#define BOARD_LED_Pin GPIO_PIN_4
#define BOARD_LED_GPIO_Port GPIOE
#define DEC_KEY_Pin GPIO_PIN_15
#define DEC_KEY_GPIO_Port GPIOA
#define DEC_KEY_EXTI_IRQn EXTI15_10_IRQn
#define INC_KEY_Pin GPIO_PIN_3
#define INC_KEY_GPIO_Port GPIOB
#define INC_KEY_EXTI_IRQn EXTI3_IRQn

/* USER CODE BEGIN Private defines */

#define		FLAG_USART_1_LINE_READY				(1u << 0)
#define		FLAG_USART_2_LINE_READY				(1u << 1)
#define		FLAG_MSG_TRANSMIT_CPLT				(1u << 2)

#define		FLAG_UPDATE_RTC						(1u << 9)
#define		FLAG_STOP_NEW_TRACK_PROCESS			(1u << 10)
#define		FLAG_TRANSMIT_GPS_DATA				(1u << 11)
#define		FLAG_LOG_GPS_DATA					(1u << 12)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
