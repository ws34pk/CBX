/*
 * messages.h
 *
 *  Created on: Oct 23, 2025
 *      Author: user
 */

#ifndef INC_MESSAGES_H_
#define INC_MESSAGES_H_

#include "main.h"

#define		MESSAGES_WAIT_FOR_FLAGS				1

#define		FLAG_GET_NO_OF_TRACKS				1
#define		FLAG_GET_TRACKS_LIST				2
#define		FLAG_START_NEW_TRACK_RECORDING		3
#define		FLAG_STOP_NEW_TRACK_RECORDING		4



const uint8_t msg_tracks_list[] = "*001\r\n";
const uint8_t msg_get_no_of_tracks[] = "*002\r\n";
const uint8_t msg_start_new_track_recording[] = "*003\r\n";
const uint8_t msg_stop_new_track_recording[] = "*004\r\n";



#endif /* INC_MESSAGES_H_ */
