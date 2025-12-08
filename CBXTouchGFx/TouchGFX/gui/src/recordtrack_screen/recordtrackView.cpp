#include <gui/recordtrack_screen/recordtrackView.hpp>
#include <touchgfx/Color.hpp>

extern "C" {
#include "main.h"
extern volatile uint32_t FLAGS_1;
extern volatile uint8_t gps_data_validity;
}

recordtrackView::recordtrackView()
{

}

void recordtrackView::setupScreen()
{
    recordtrackViewBase::setupScreen();
}

void recordtrackView::tearDownScreen()
{
    recordtrackViewBase::tearDownScreen();
}

void recordtrackView::check_buttons(uint8_t buttons_state)
{
	static uint8_t flag_start_status=0;
	if(buttons_state == 0x02) {
		if(startbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(!flag_start_status) {
				flag_start_status = 1;
				//flag_start_new_track_recording = 1;
				set_flag(&FLAGS_1, FLAG_START_NEW_TRACK_RECORDING);
				Unicode::snprintf(starttextBuffer, STARTTEXT_SIZE, "STOP");
			} else {
				flag_start_status = 0;
				//flag_stop_new_track_recording = 1;
				set_flag(&FLAGS_1, FLAG_STOP_NEW_TRACK_RECORDING);
				Unicode::snprintf(starttextBuffer, STARTTEXT_SIZE, "START");
			}
		}
		if(backbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			//return to the main menu
			static_cast<FrontendApplication*>(Application::getInstance())->gotoaddnewtrackScreenNoTransition();
		mainbox.invalidate();
	}
	if(buttons_state == 0x04) {
		if(startbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			startbox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			backbox.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(backbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			backbox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			startbox.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		mainbox.invalidate();
			//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
	Unicode::snprintf(testtextBuffer, TESTTEXT_SIZE,"%c",gps_data_validity);
	if(gps_data_validity == 'V')
		gps_status_indicatorPainter.setColor(touchgfx::Color::getColorFromRGB(0xff, 0xff, 0xff));
	else if ((gps_data_validity == 'A'))
		gps_status_indicatorPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0xff, 0));
	else
		gps_status_indicatorPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

	gps_status_indicator.invalidate();
	mainbox.invalidate();
}
