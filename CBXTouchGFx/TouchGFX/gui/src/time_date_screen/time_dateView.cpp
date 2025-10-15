#include <gui/time_date_screen/time_dateView.hpp>
#include <touchgfx/Color.hpp>

extern "C" {
#include "rtc.h"
extern volatile RTC_DateTypeDef rtc_date;
extern volatile RTC_TimeTypeDef rtc_time;
}

time_dateView::time_dateView()
{
	Unicode::snprintf(date_textBuffer, sizeof(date_textBuffer), "%02d", rtc_date.Date);
	Unicode::snprintf(month_textBuffer, sizeof(month_textBuffer), "%02d", rtc_date.Month);
	Unicode::snprintf(year_textBuffer, sizeof(year_textBuffer), "20%02d", rtc_date.Year);
	Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
	Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
}

void time_dateView::setupScreen()
{
    time_dateViewBase::setupScreen();
}

void time_dateView::tearDownScreen()
{
    time_dateViewBase::tearDownScreen();
}

void time_dateView::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x01)
		static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();
	if(buttons_state == 0x02) {
		if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoset_dateScreenNoTransition();
		if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoset_timeScreenNoTransition();
	}

	if(buttons_state == 0x04) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box5.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
	}
	if(buttons_state == 0x08) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box5.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
		//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
}
