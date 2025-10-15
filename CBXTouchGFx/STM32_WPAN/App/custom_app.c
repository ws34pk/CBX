/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_app.c
  * @author  MCD Application Team
  * @brief   Custom Example Application (Server)
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
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  /* My_CBX_Server */
  uint8_t               My_gps_Notification_Status;
  uint8_t               La_dat_Notification_Status;
  /* USER CODE BEGIN CUSTOM_APP_Context_t */

  /* USER CODE END CUSTOM_APP_Context_t */

  uint16_t              ConnectionHandle;
} Custom_App_Context_t;

/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/**
 * START of Section BLE_APP_CONTEXT
 */

static Custom_App_Context_t Custom_App_Context;

/**
 * END of Section BLE_APP_CONTEXT
 */

uint8_t UpdateCharData[512];
uint8_t NotifyCharData[512];
uint16_t Connection_Handle;
/* USER CODE BEGIN PV */
extern uint8_t gps_fix_status;
extern uint8_t tempcount;
//extern uint8_t gps_msg_buf[7][86];
extern uint8_t gps_lat_data[10];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* My_CBX_Server */
static void Custom_My_gps_Update_Char(void);
static void Custom_My_gps_Send_Notification(void);
static void Custom_La_dat_Update_Char(void);
static void Custom_La_dat_Send_Notification(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_1 */

  /* USER CODE END CUSTOM_STM_App_Notification_1 */
  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* USER CODE END CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* My_CBX_Server */
    case CUSTOM_STM_MY_GPS_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_MY_GPS_NOTIFY_ENABLED_EVT */
    	Custom_App_Context.My_gps_Notification_Status = 1;
      /* USER CODE END CUSTOM_STM_MY_GPS_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_MY_GPS_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_MY_GPS_NOTIFY_DISABLED_EVT */
    	Custom_App_Context.My_gps_Notification_Status = 0;
      /* USER CODE END CUSTOM_STM_MY_GPS_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_LA_DAT_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_LA_DAT_NOTIFY_ENABLED_EVT */
    	Custom_App_Context.La_dat_Notification_Status = 1;
      /* USER CODE END CUSTOM_STM_LA_DAT_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_LA_DAT_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_LA_DAT_NOTIFY_DISABLED_EVT */
    	Custom_App_Context.La_dat_Notification_Status = 0;
      /* USER CODE END CUSTOM_STM_LA_DAT_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_NOTIFICATION_COMPLETE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_NOTIFICATION_COMPLETE_EVT */

      /* USER CODE END CUSTOM_STM_NOTIFICATION_COMPLETE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_STM_App_Notification_default */

      /* USER CODE END CUSTOM_STM_App_Notification_default */
      break;
  }
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_2 */

  /* USER CODE END CUSTOM_STM_App_Notification_2 */
  return;
}

void Custom_APP_Notification(Custom_App_ConnHandle_Not_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_APP_Notification_1 */

  /* USER CODE END CUSTOM_APP_Notification_1 */

  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_APP_Notification_Custom_Evt_Opcode */

    /* USER CODE END P2PS_CUSTOM_Notification_Custom_Evt_Opcode */
    case CUSTOM_CONN_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_CONN_HANDLE_EVT */

      /* USER CODE END CUSTOM_CONN_HANDLE_EVT */
      break;

    case CUSTOM_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_DISCON_HANDLE_EVT */

      /* USER CODE END CUSTOM_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_APP_Notification_default */

      /* USER CODE END CUSTOM_APP_Notification_default */
      break;
  }

  /* USER CODE BEGIN CUSTOM_APP_Notification_2 */

  /* USER CODE END CUSTOM_APP_Notification_2 */

  return;
}

void Custom_APP_Init(void)
{
  /* USER CODE BEGIN CUSTOM_APP_Init */
	UTIL_SEQ_RegTask(1<<CFG_TASK_UPDATE_GPS_DATA_ID, UTIL_SEQ_RFU, Custom_My_gps_Send_Notification);
	Custom_App_Context.My_gps_Notification_Status = 0;
  /* USER CODE END CUSTOM_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

/* My_CBX_Server */
__USED void Custom_My_gps_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN My_gps_UC_1*/

  /* USER CODE END My_gps_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_MY_GPS, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN My_gps_UC_Last*/

  /* USER CODE END My_gps_UC_Last*/
  return;
}

void Custom_My_gps_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN My_gps_NS_1*/
  if (Custom_App_Context.My_gps_Notification_Status == 1) {
  		updateflag = 1;
  		//NotifyCharData = &gps_msg_buf[0][0];
  		Custom_App_Context.My_gps_Notification_Status = 0;
  	}
  /* USER CODE END My_gps_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_MY_GPS, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN My_gps_NS_Last*/

  /* USER CODE END My_gps_NS_Last*/

  return;
}

__USED void Custom_La_dat_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN La_dat_UC_1*/

  /* USER CODE END La_dat_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_LA_DAT, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN La_dat_UC_Last*/

  /* USER CODE END La_dat_UC_Last*/
  return;
}

void Custom_La_dat_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN La_dat_NS_1*/

  /* USER CODE END La_dat_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_LA_DAT, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN La_dat_NS_Last*/

  /* USER CODE END La_dat_NS_Last*/

  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/
void myTask(void)
{
	static uint8_t flag=0;
	if(flag)
	{
		flag = 0;
		//Custom_STM_App_Update_Char(CUSTOM_STM_MY_GPS, &gps_msg_buf[0][0]);

	} else {
		flag = 1;
		Custom_STM_App_Update_Char(CUSTOM_STM_LA_DAT, &gps_lat_data[0]);
	}
	//Custom_STM_App_Update_Char(CUSTOM_STM_MY_GPS, &gps_msg_buf[0][0]);
	//Custom_STM_App_Update_Char(CUSTOM_STM_LA_DAT, &gps_lat_data[0]);
	UTIL_SEQ_SetTask(1<<CFG_TASK_UPDATE_GPS_DATA_ID, CFG_SCH_PRIO_0);
}
/* USER CODE END FD_LOCAL_FUNCTIONS*/
