#include <gui/set_time_screen/set_timeView.hpp>
#include <touchgfx/Color.hpp>

extern "C" {
#include "main.h"
#include "rtc.h"
extern volatile RTC_DateTypeDef rtc_date;
extern volatile RTC_TimeTypeDef rtc_time;
//extern volatile uint8_t flag_update_rtc;
extern volatile uint32_t FLAGS_1;
}

set_timeView::set_timeView()
{
	Unicode::snprintf(date_textBuffer, sizeof(date_textBuffer), "%02d", rtc_date.Date);
	Unicode::snprintf(month_textBuffer, sizeof(month_textBuffer), "%02d", rtc_date.Month);
	Unicode::snprintf(year_textBuffer, sizeof(year_textBuffer), "20%02d", rtc_date.Year);
	Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
	Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
}

void set_timeView::setupScreen()
{
    set_timeViewBase::setupScreen();
}

void set_timeView::tearDownScreen()
{
    set_timeViewBase::tearDownScreen();
}

void set_timeView::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x04) {
		if(hr_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			rtc_time.Hours++;
			if(rtc_time.Hours > 23) {
				rtc_time.Hours = 0;
			}
			Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
		} else if (min_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			rtc_time.Minutes++;
			if(rtc_time.Minutes > 59) {
				rtc_time.Minutes = 0;
			}
			Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
		}
		//flag_update_rtc = 1;
		set_flag(&FLAGS_1, FLAG_UPDATE_RTC);
		box1.invalidate();
	}
	if(buttons_state == 0x08) {
		if(hr_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(rtc_time.Hours) rtc_time.Hours--;
			else rtc_time.Hours = 23;
			Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
		} else if (min_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(rtc_time.Minutes)
				rtc_time.Minutes--;
			else
				rtc_time.Minutes = 59;
			Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
		}
		//flag_update_rtc = 1;
		set_flag(&FLAGS_1, FLAG_UPDATE_RTC);
		box1.invalidate();
	}
	if(buttons_state == 0x02) {
		if(hr_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			hr_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			min_box.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if (min_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			min_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			hr_box.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
	}

	Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
	Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
	box1.invalidate();
}
