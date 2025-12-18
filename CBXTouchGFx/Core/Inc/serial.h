/*
 * serial.h
 *
 *  Created on: Oct 23, 2025
 *      Author: user
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#include "main.h"

#define	RX_BUF_SIZE				128
#define	LINE_BUF_SIZE			64

void UART_1_LineReader_Init(void);
uint8_t UART_1_LineAvailable(void);
char* UART_1_GetLine(void);

HAL_StatusTypeDef usart_send_message(const uint8_t *msg);

uint8_t check_messages_flags(void);

void transmit_messages_process(void);
void received_messages_process(void);
void serial_comm_process(void);

void format_track_names(void);

void extract_gps_data(uint8_t *gps_msg);
uint8_t extract_no_of_tracks(uint8_t *gps_msg);

#endif /* INC_SERIAL_H_ */
