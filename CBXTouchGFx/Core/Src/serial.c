/*
 * serial.c
 *
 *  Created on: Oct 23, 2025
 *      Author: user
 */
#include "usart.h"
#include "serial.h"
#include "stdio.h"
#include "messages.h"

#define		MAX_NO_OF_MSGS		4
#define		MSG_BUFF_SIZE		64
#define		MSG_BUFF_INDEX_MAX	MSG_BUFF_SIZE - 1

uint8_t usart1_rx_buf[RX_BUF_SIZE];
volatile uint8_t usart1_line_buf[LINE_BUF_SIZE];   // Line buffer

volatile uint8_t flag_uart_1_lineReady=0;

extern UART_HandleTypeDef huart1;

//GUI flags
volatile uint8_t flag_get_no_of_tracks = 0;
volatile uint8_t flag_start_new_track_recording = 0;
volatile uint8_t flag_stop_new_track_recording = 0;

uint8_t msg_buff[MAX_NO_OF_MSGS][MSG_BUFF_SIZE];
volatile uint8_t msg_buff_index = 0;
volatile uint8_t processed_msg_index = 0;

volatile float gps_lat, gps_lon;
volatile uint8_t gps_status;
volatile uint8_t gps_data_validity;

volatile uint8_t no_of_tracks = 0;

void serial_comm_process(void)
{
	if(UART_1_LineAvailable()) {
		char *line = UART_1_GetLine();
		uint8_t bytes = strlen(line);
		memcpy(&msg_buff[msg_buff_index][1], line, bytes);
		msg_buff[msg_buff_index][0] = bytes;
		msg_buff_index++;
		if(msg_buff_index > (MAX_NO_OF_MSGS -1))
			msg_buff_index = 0;
	}
}

void UART_1_LineReader_Init(void)
{
    // Start DMA in circular mode
    HAL_UART_Receive_DMA(&huart1, usart1_rx_buf, RX_BUF_SIZE);

    // 1. Disable USART
    CLEAR_BIT(USART1->CR1, USART_CR1_UE);

    // 2. Set match character, e.g. '\n'
    //MODIFY_REG(USART1->CR2, USART_CR2_ADD, (uint32_t)'\n');

    USART1->CR2 = USART1->CR2 & 0x00FFFFFF;
    USART1->CR2 = USART1->CR2 | 0x0A000000;
    // 3. Enable Character Match Interrupt
    SET_BIT(USART1->CR1, USART_CR1_CMIE);

    // 4. Re-enable USART
    SET_BIT(USART1->CR1, USART_CR1_UE);

    // Enable IRQ
    //HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    //HAL_NVIC_EnableIRQ(USART1_IRQn);
}

HAL_StatusTypeDef usart_send_message(const uint8_t *msg)
{
	if(msg == NULL)
		return(HAL_ERROR);
	HAL_UART_Transmit_DMA(&huart1, (char *)msg, strlen(msg));
	return(HAL_OK);
}

void transmit_messages_process(void)
{
	static uint8_t messages_process_state = MESSAGES_WAIT_FOR_FLAGS;
	//check the status of the various flags
	uint8_t temp = check_messages_flags();
	switch(messages_process_state)
	{
		case MESSAGES_WAIT_FOR_FLAGS:
			if(temp == FLAG_GET_NO_OF_TRACKS)
				usart_send_message(msg_get_no_of_tracks);
			else if(temp == FLAG_START_NEW_TRACK_RECORDING)
				//usart_send_message("start_new_track_recording\r\n");
				usart_send_message(msg_start_new_track_recording);
			else if(temp == FLAG_STOP_NEW_TRACK_RECORDING)
				usart_send_message(msg_stop_new_track_recording);
			break;
		default:
			break;
	}
}

void received_messages_process(void)
{
	int8_t status;
	if(processed_msg_index != msg_buff_index)
	{
		/*
		status = strncmp(&msg_buff[processed_msg_index][1],"new_track_process_started\r\n",msg_buff[processed_msg_index][0]);
		if(!status)
			//usart_send_message("new_track_process_started\r\n");
			status+=1;
		else {
			status = strncmp(&msg_buff[processed_msg_index][1],"*001",4);
			if(!status) {
				extract_gps_data(&msg_buff[processed_msg_index][0]);
				status+=2;
			}
		}
		*/
		if(!strncmp(&msg_buff[processed_msg_index][1],"new_track_process_started\r\n",msg_buff[processed_msg_index][0])) {

		}
		else if(!strncmp(&msg_buff[processed_msg_index][1],"*001",4))
			extract_gps_data(&msg_buff[processed_msg_index][0]);
		else if(!strncmp(&msg_buff[processed_msg_index][1],"*002",4))
			no_of_tracks = extract_no_of_tracks(&msg_buff[processed_msg_index][0]);

		processed_msg_index++;
		if(processed_msg_index > (MAX_NO_OF_MSGS -1))
			processed_msg_index = 0;
	}
}

uint8_t check_messages_flags(void)
{
	if(flag_get_no_of_tracks) {
		flag_get_no_of_tracks = 0; return(FLAG_GET_NO_OF_TRACKS);
	}
	else if(flag_start_new_track_recording) {
		flag_start_new_track_recording = 0; return(FLAG_START_NEW_TRACK_RECORDING);
	}
	else if(flag_stop_new_track_recording) {
		flag_stop_new_track_recording = 0; return(FLAG_STOP_NEW_TRACK_RECORDING);
	}
	else return(0);
}

uint8_t UART_1_LineAvailable(void)
{
    return flag_uart_1_lineReady;
}

char* UART_1_GetLine(void)
{
	flag_uart_1_lineReady = 0;
    return (char*)usart1_line_buf;
}

void extract_gps_data(uint8_t *gps_msg)
{
	uint8_t i;
	uint8_t no_of_bytes;
	uint8_t indices[5];
	uint8_t count=0;
	uint8_t *temp_str = {0};

	no_of_bytes = gps_msg[0];

	for(i=0; i<no_of_bytes; i++) {
		if(gps_msg[i+4] == ',')
			indices[count++] = i+4;
	}
	if(count) {
		no_of_bytes = indices[0] - 3;
		strncpy(temp_str,&gps_msg[indices[0]],no_of_bytes);
		gps_lat = atof(temp_str);

		no_of_bytes = indices[1] - indices[0];
		strncpy(temp_str,&gps_msg[indices[0]],no_of_bytes);
		gps_lat = atof(temp_str);

		gps_data_validity = gps_msg[indices[1]+1];
	}
}

uint8_t extract_no_of_tracks(uint8_t *gps_msg)
{
	uint8_t no_of_tracks;
	char bytes[2];

	memcpy(bytes, &gps_msg[5], 2);


	no_of_tracks = atoi(bytes);
	//no_of_tracks = ((gps_msg[5] - 0x30) * 10) + (gps_msg[6] - 0x30);
	return(no_of_tracks);
}
