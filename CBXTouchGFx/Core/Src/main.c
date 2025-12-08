/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dma.h"
#include "ipcc.h"
#include "quadspi.h"
#include "rf.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "z_displ_ILI9XXX.h"
#include "z_touch_XPT2046.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "track.h"
#include "arm_math.h"
#include "serial.h"
//#include "messages.h"
//#include "uart.h"
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
__IO uint8_t sel_key_state = 0;
__IO uint8_t set_key_state = 0;
__IO uint8_t inc_key_state = 0;
__IO uint8_t dec_key_state = 0;
uint32_t touch_gfx_update_time;

uint8_t usart_rx_buff[30];
volatile uint8_t flag_usart_tfr_cplt = 0;

uint8_t gps_lat_data[12];
uint8_t gps_long_data[12];

volatile uint16_t i=0;


volatile uint16_t count=0;

volatile uint8_t position;


uint8_t gps_fix_status;

uint32_t current_time;
uint8_t tempcount=0;

//uint8_t flag_get_no_of_tracks = 0;

volatile uint32_t button_dly;


uint8_t Readbuf[100];
extern volatile float slope;
extern volatile float c1;
extern volatile float new_displacement;
volatile float lat, lon;
uint8_t lati[10];

volatile RTC_DateTypeDef rtc_date;
volatile RTC_TimeTypeDef rtc_time;
//volatile uint8_t flag_update_rtc = 0;

volatile uint8_t flag_track_start_stop=0;
volatile uint8_t flag_update_gps_data = 0;

volatile uint32_t FLAGS_1 = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */
void gps_data_process(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void gps_data_process(void)
{
	if(flag_usart_tfr_cplt){
		flag_usart_tfr_cplt = 0;
		memcpy(gps_lat_data,&usart_rx_buff[0],11);
		memcpy(gps_long_data,&usart_rx_buff[12],11);
		//extract_gps_data(&gps_msg_buf[0][0], &lat, &lon);

		//sprintf(gps_lat_data,"%4.4f",lat);
		//sprintf(gps_long_data,"%4.4f",lon);
		displacement_from_line(slope, lon, lat, c1, &new_displacement);
		new_displacement = new_displacement * 10;
		sprintf(lati,"%2.6f",new_displacement);
		HAL_UART_Receive_DMA(&huart1, usart_rx_buff, 24);
		flag_update_gps_data = 1;
	}

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
static uint8_t count=0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Config code for STM32_WPAN (HSE Tuning must be done before system clock configuration) */
  MX_APPE_Config();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* IPCC initialisation */
  MX_IPCC_Init();

  /* USER CODE BEGIN SysInit */
  HAL_Delay(1000);

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_CRC_Init();
  MX_TIM2_Init();
  MX_QUADSPI_Init();
  MX_USART1_UART_Init();
  MX_RTC_Init();
  MX_TouchGFX_Init();
  MX_RF_Init();
  /* USER CODE BEGIN 2 */

  rtc_date.Date = 1;
  rtc_date.Month = 1;
  rtc_date.Year = 25;
  rtc_time.Hours = 12;
  rtc_time.Minutes = 0;

  HAL_RTC_SetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN);
  HAL_RTC_SetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN);

  HAL_Delay(500);


  //uint8_t writebuf[] = "External Loader Not Working";

  if (CSP_QUADSPI_Init() != HAL_OK) Error_Handler();

  //if (CSP_QSPI_Erase_Chip() != HAL_OK) Error_Handler();

  //if (CSP_QSPI_WriteMemory(writebuf, 0, sizeof(writebuf)) != HAL_OK) Error_Handler();

  //if (CSP_QSPI_Read(Readbuf, 0, 100) != HAL_OK) Error_Handler();

  if (CSP_QSPI_EnableMemoryMappedMode() != HAL_OK) Error_Handler();

  memcpy(Readbuf, (uint8_t *) 0x90000000, 100);
//	if (Readbuf[0] == 'A') {
//		HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin, 1);
//	} else {
//		HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin, 0);
//	}
  Displ_Init(Displ_Orientat_90);			// initialize display controller - set orientation parameter as per TouchGFX setup
  touchgfxSignalVSync();					// ask display syncronization
  Displ_BackLight('I');  					// initialize backlight

  line_slope(72.7302, 33.7771, 72.7304, 33.7769, &slope, &c1);
  displacement_from_line(slope, 72.73041786, 33.77714404, c1, &new_displacement);
  displacement_from_line(slope, 72.73012149, 33.7768531, c1, &new_displacement);

  check_crossing_point(72.7302, 33.7771, 72.7304, 33.7769, 72.7304, 33.7774);
  check_crossing_point(72.7302, 33.7771, 72.7304, 33.7769, 72.73044467, 33.77714712);
  touch_gfx_update_time = HAL_GetTick();
  //HAL_UART_Receive_DMA(&huart1, usart_rx_buff, 24);
  UART_1_LineReader_Init();
  current_time = HAL_GetTick();
  button_dly = HAL_GetTick();
  //HAL_NVIC_EnableIRQ(USART1_IRQn);
  //send a test message

  /* USER CODE END 2 */

  /* Init code for STM32_WPAN */
  MX_APPE_Init();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  serial_comm_process();
	  transmit_messages_process();
	  received_messages_process();
	//send bluetooth data
	if ((current_time + 1000) < HAL_GetTick()) {
		current_time = HAL_GetTick();
		myTask();
		//also update the time and date
		HAL_RTC_GetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc,&rtc_date,RTC_FORMAT_BIN);
		track_process();
		if(count < 10) {
			++count;
			if(count > 6)
			usart_send_message("HelloWorld\r\n");
		}
	}
	//gps_data_process();
	if((touch_gfx_update_time+100) < HAL_GetTick())
	{
		touchgfxSignalVSync();					// ask display syncronization
		touch_gfx_update_time = HAL_GetTick();
	}
	//if(flag_update_rtc)
	if(read_flag(&FLAGS_1, FLAG_UPDATE_RTC))
	{
		//flag_update_rtc = 0;
		clear_flag(&FLAGS_1, FLAG_UPDATE_RTC);
		HAL_RTC_SetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN);
		HAL_RTC_SetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN);
	}
	//track_process();
    /* USER CODE END WHILE */
    MX_APPE_Process();

  MX_TouchGFX_Process();
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI1
                              |RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK4|RCC_CLOCKTYPE_HCLK2
                              |RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK2Divider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.AHBCLK4Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SMPS|RCC_PERIPHCLK_RFWAKEUP;
  PeriphClkInitStruct.RFWakeUpClockSelection = RCC_RFWKPCLKSOURCE_HSE_DIV1024;
  PeriphClkInitStruct.SmpsClockSelection = RCC_SMPSCLKSOURCE_HSE;
  PeriphClkInitStruct.SmpsDivSelection = RCC_SMPSCLKDIV_RANGE1;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN Smps */

  /* USER CODE END Smps */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		flag_usart_tfr_cplt = 1;
		//HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	static uint32_t last_tick=0;
	uint32_t current_tick;
	current_tick = HAL_GetTick();
	if(current_tick > (last_tick+200))
	{
		last_tick = current_tick;
		if(GPIO_Pin == SEL_KEY_Pin)
			sel_key_state = 1;
		else if(GPIO_Pin == SET_KEY_Pin)
			set_key_state = 1;
		else if(GPIO_Pin == INC_KEY_Pin)
			inc_key_state = 1;
		else if(GPIO_Pin == DEC_KEY_Pin)
			dec_key_state = 1;
	}
}

//sets a single bit in a 32 bit variable
void set_flag(volatile uint32_t *flag_variable, uint32_t flag)
{
	*flag_variable = *flag_variable | flag;
}
//clears a single bit in a 32-bit variable
void clear_flag(volatile uint32_t *flag_variable, uint32_t flag)
{
	*flag_variable = *flag_variable & ~flag;
}
//returns the value of a single bit in a 32-bit variable
uint32_t read_flag(volatile uint32_t *flag_variable, uint32_t flag)
{
	return(*flag_variable & flag);
}

/*
void DisplayDriver_TransferCompleteCallback()
{

}
void touchgfxSignalVSync(void)
{

}
*/
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
#ifdef USE_FULL_ASSERT
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
