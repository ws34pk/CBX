/*
 * track.c
 *
 *  Created on: Mar 23, 2025
 *      Author: waseem.wecuw
 */
#include "main.h"
#include "track.h"
#include "arm_math.h"

#define CROSSING_LINE1_CALCULATION 		0
#define WAIT_FOR_START 					1
#define WAIT_FOR_FIRST_LINE_CROSSING 	2
#define CROSSING_LINE2_CALCULATION 		3
#define WAIT_FOR_SECOND_LINE_CROSSING 	4
#define CROSSING_LINE3_CALCULATION 		5
#define WAIT_FOR_THIRD_LINE_CROSSING 	6
#define CROSSING_LINE4_CALCULATION 		7
#define WAIT_FOR_FOURTH_LINE_CROSSING 	8


extern volatile uint8_t flag_track_start_stop;
extern volatile float lat,lon;

volatile float slope;
volatile float c1;
volatile float new_displacement;
volatile float old_displacement;
volatile uint8_t track_status=0;



/*
 * Calculates the slope of the line between two points (x1,y1) and (x2,y2)
 */
void line_slope(float x1, float y1, float x2, float y2, float *slope, float *c) {
	*slope = (y2 - y1) / (x2 - x1);
	*c = y1 - (*slope * x1);
}
/*
 * Calculates the displacement of a point (x,y) from a line
 */
void displacement_from_line(float line_slope, float x, float y, float c1,
		float *displacement) {
	float c2;
	c2 = y - (line_slope * x);
	*displacement = ((c2 - c1)/sqrt((line_slope * line_slope) + 1));
}
/*
 * Checks if the crossing point lines between the ends of the control line
 */
uint8_t check_crossing_point(float x1, float y1, float x2, float y2, float x3,
		float y3) {
	double A, B, C, D, t;
	A = x3 - x1;
	B = y3 - y1;
	C = x2 - x1;
	D = y2 - y1;

	t = ((A * C) + (B * D))/((C * C) + (D * D));
	if(t > 0 && t < 1) {
		HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);
		return (1);
	}
	else {
		return (0);
	}
	/*
	A = y2 - y1;
	B = x1 - x2;

	product = (A * A) + (B * B);

	C = ((x2 * y1)-(x1 * y2));

	D = (A * y3) - (B * x3);

	//y = ((B * D) - (A * C)) / product;

	//x = ((A * (-D)) - (B * C)) / product;

	x = -((B * D) + (A * C))/product;
	y = ((B * x) + D)/A;


	if (MIN(x1, x2) <= x && x <= MAX(x1, x2) && MIN(y1, y2) <= y
			&& y <= MAX(y1, y2)) {
		HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin, 1);
		return (1);
	} else {
		HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin, 0);
		return (0);
	}
	*/

}

void track_process(void) {
	static uint8_t track_process_status = CROSSING_LINE1_CALCULATION;

	if(!flag_track_start_stop){
		if(track_process_status)
			track_process_status = 0;
		if(track_status)
			track_status = 0;
	} else {
		switch (track_process_status) {
		case CROSSING_LINE1_CALCULATION:
		{
			line_slope(72.7381, 33.7788, 72.7384, 33.7793, &slope, &c1);
			//line_slope(72.7305, 33.7771, 72.7306, 33.777, &slope, &c1);
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			track_process_status = WAIT_FOR_START;
		}
		break;
		case WAIT_FOR_START:
		{
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			old_displacement = new_displacement;
			track_process_status = WAIT_FOR_FIRST_LINE_CROSSING;
		}
		break;

		case WAIT_FOR_FIRST_LINE_CROSSING: {
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			if (new_displacement > 0 && old_displacement < 0) {
				if (check_crossing_point(72.7381, 33.7788, 72.7384, 33.7793,
						lon, lat)) {
					track_status = 1;
					old_displacement = new_displacement;
					track_process_status = CROSSING_LINE2_CALCULATION;
				}
			} else if (new_displacement < 0 && old_displacement > 0) {
				if (check_crossing_point(72.7381, 33.7788, 72.7384, 33.7793,
										lon, lat)) {
									track_status = 1;
									old_displacement = new_displacement;
									track_process_status = CROSSING_LINE2_CALCULATION;
			}
		}
		break;
		case CROSSING_LINE2_CALCULATION: {
			line_slope(72.7391, 33.7788, 72.7395, 33.7785, &slope, &c1);
			//line_slope(72.7299, 33.7765, 72.73, 33.7764, &slope, &c1);
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			track_process_status = WAIT_FOR_SECOND_LINE_CROSSING;
		}
		break;
		case WAIT_FOR_SECOND_LINE_CROSSING: {
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			if (new_displacement > 0 && old_displacement < 0) {
					if (check_crossing_point(72.7391, 33.7788, 72.7395, 33.7785,
							lon, lat)) {
						track_status = 2;
						old_displacement = new_displacement;
						track_process_status = CROSSING_LINE3_CALCULATION;
					}
				} else if (new_displacement < 0 && old_displacement > 0) {
					if (check_crossing_point(72.7391, 33.7788, 72.7395, 33.7785,
							lon, lat)) {
						track_status = 2;
						old_displacement = new_displacement;
						track_process_status = CROSSING_LINE3_CALCULATION;
					}
			}
		}
		case CROSSING_LINE3_CALCULATION: {
			line_slope(72.7385, 33.7794, 72.7387, 33.7797, &slope, &c1);
			//line_slope(72.73, 33.7766, 72.72989,33.7767, &slope, &c1);
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			track_process_status = WAIT_FOR_THIRD_LINE_CROSSING;
		}
		break;
		case WAIT_FOR_THIRD_LINE_CROSSING: {
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			if (new_displacement > 0 && old_displacement < 0) {
				if (check_crossing_point(72.7385, 33.7794, 72.7387, 33.7797,
						lon, lat)) {
					track_status = 3;
					old_displacement = new_displacement;
					track_process_status = CROSSING_LINE4_CALCULATION;
				}
			} else if (new_displacement < 0 && old_displacement > 0) {
				if (check_crossing_point(72.7385, 33.7794, 72.7387, 33.7797,
						lon, lat)) {
					track_status = 3;
					old_displacement = new_displacement;
					track_process_status = CROSSING_LINE4_CALCULATION;
				}
			}
		}
		break;
		case CROSSING_LINE4_CALCULATION: {
			line_slope(72.7375,33.7799,72.7377,33.7797, &slope, &c1);
			//line_slope(72.73056,33.7774,72.7307,33.77728, &slope, &c1);
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			track_process_status = WAIT_FOR_FOURTH_LINE_CROSSING;
		}
		break;
		case WAIT_FOR_FOURTH_LINE_CROSSING: {
			displacement_from_line(slope, lon, lat, c1, &new_displacement);
			if (new_displacement > 0 && old_displacement < 0) {
				if (check_crossing_point(72.7375,33.7799,72.7377,33.7797,
							lon, lat)) {
						track_status = 4;
						old_displacement = new_displacement;
						track_process_status = CROSSING_LINE1_CALCULATION;
					}
			} else if (new_displacement < 0 && old_displacement > 0) {
				if (check_crossing_point(72.7375,33.7799,72.7377,33.7797,
							lon, lat)) {
						track_status = 4;
						old_displacement = new_displacement;
						track_process_status = CROSSING_LINE1_CALCULATION;
					}
			}
		}
		default:
			break;
		}
	}
	}
}


