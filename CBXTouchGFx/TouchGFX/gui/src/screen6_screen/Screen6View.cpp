#include <gui/screen6_screen/Screen6View.hpp>
#include <touchgfx/Color.hpp>
extern "C" {
#include "usart.h"
//extern UART_HandleTypeDef huart1;
extern uint8_t gps_lat_data[10];
extern uint8_t gps_long_data[10];
extern uint8_t lati[10];
extern volatile uint8_t flag_update_gps_data;
extern volatile uint8_t flag_track_start_stop;
extern volatile uint8_t track_status;
}

uint8_t usart1_tx_buff[10];

Screen6View::Screen6View()
{

}

void Screen6View::setupScreen()
{
    Screen6ViewBase::setupScreen();
}

void Screen6View::tearDownScreen()
{
    Screen6ViewBase::tearDownScreen();
    flag_update_gps_data = 0;
}

void Screen6View::check_buttons(uint8_t buttons_state)
{
	//int8_t tempStr[20];
	//sprintf((char*)tempStr, "%4.4f", latitude);
	//Unicode::fromUTF8((const uint8_t*)tempStr, testBuffer, TEST_SIZE);

	if(flag_update_gps_data == 1)
	{
		Unicode::fromUTF8((const uint8_t*)lati, testBuffer, TEST_SIZE);
		Unicode::fromUTF8((const uint8_t*)gps_lat_data, latitudeBuffer, LATITUDE_SIZE);
		Unicode::fromUTF8((const uint8_t*)gps_long_data, longitudeBuffer, LONGITUDE_SIZE);

		box1.invalidate();
		flag_update_gps_data = 0;
	}
	//Unicode::fromUTF8(gps_lat_data, latitudeBuffer, LATITUDE_SIZE);
	//Unicode::fromUTF8(gps_long_data, longitudeBuffer, LONGITUDE_SIZE);
	//box1.invalidate();
	if(buttons_state == 0x01){
		static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();
	}
	if(buttons_state == 0x04) {
		Unicode::fromUTF8((const uint8_t*)gps_lat_data, latitudeBuffer, LATITUDE_SIZE);
		Unicode::fromUTF8((const uint8_t*)gps_long_data, longitudeBuffer, LONGITUDE_SIZE);
		//Unicode::snprintf(longitudeBuffer, LONGITUDE_SIZE, "12345.919");
		//latitude.invalidate();
		//longitude.invalidate();
		box1.invalidate();
	}
	if(buttons_state == 0x08) {
		Unicode::snprintf(latitudeBuffer, LATITUDE_SIZE, "1234.817");
		Unicode::snprintf(longitudeBuffer,LONGITUDE_SIZE , "276989");
		//latitude.invalidate();
		//longitude.invalidate();
		box1.invalidate();
	}
	if(buttons_state == 0x02){
		if(flag_track_start_stop == 0) {
			Unicode::snprintf(start_textBuffer, START_TEXT_SIZE, "STOP");
			flag_track_start_stop = 1;
			usart1_tx_buff[0] = 'S';
		} else {
			Unicode::snprintf(start_textBuffer, START_TEXT_SIZE, "START");
			usart1_tx_buff[0] = 'P';
			flag_track_start_stop = 0;
		}
		HAL_UART_Transmit(&huart1, usart1_tx_buff, 1, 10);
		box1.invalidate();
	}
	if(flag_track_start_stop == 1) {
		if(track_status == 1) {
			seg1.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			//seg2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		} else if(track_status == 2) {
			//seg1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			seg2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			//seg3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		} else if(track_status == 3) {
			//seg1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			seg3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			//seg4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		} else if(track_status == 4) {
			//seg1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			//seg3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			seg4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
	} else
	if(track_status == 0) {
		seg1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		seg2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		seg3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		seg4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}
	box1.invalidate();
}
