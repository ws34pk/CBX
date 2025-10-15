/*
 * track.h
 *
 *  Created on: Mar 23, 2025
 *      Author: waseem.wecuw
 */

#ifndef INC_TRACK_H_
#define INC_TRACK_H_

void line_slope(float x1, float y1, float x2, float y2, float *slope, float *c);
void displacement_from_line(float line_slope, float x, float y, float c, float *displacement);
uint8_t check_crossing_point(float x1, float y1, float x2, float y2, float x3, float y3);
void track_process(void);

#endif /* INC_TRACK_H_ */
