#include <gui/set_date_screen/set_dateView.hpp>
#include <touchgfx/Color.hpp>

extern "C" {
#include "rtc.h"
extern volatile RTC_DateTypeDef rtc_date;
extern volatile RTC_TimeTypeDef rtc_time;
extern volatile uint8_t flag_update_rtc;
}

set_dateView::set_dateView()
{
	Unicode::snprintf(date_textBuffer, sizeof(date_textBuffer), "%02d", rtc_date.Date);
	Unicode::snprintf(month_textBuffer, sizeof(month_textBuffer), "%02d", rtc_date.Month);
	Unicode::snprintf(year_textBuffer, sizeof(year_textBuffer), "20%02d", rtc_date.Year);
	Unicode::snprintf(min_textBuffer, sizeof(min_textBuffer), "%02d", rtc_time.Minutes);
	Unicode::snprintf(hr_textBuffer, sizeof(hr_textBuffer), "%02d", rtc_time.Hours);
}

void set_dateView::setupScreen()
{
    set_dateViewBase::setupScreen();
}

void set_dateView::tearDownScreen()
{
    set_dateViewBase::tearDownScreen();
}

void set_dateView::check_buttons(uint8_t buttons_state)
{
	//Unicode::snprintf(textBuffer, sizeof(textBuffer), "%.2f", value);
	if(buttons_state == 0x02) {
		if(date_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			date_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			month_box.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if (month_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			month_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			year_box.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if (year_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			year_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			date_box.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
	}
	if(buttons_state == 0x04) {

		if(date_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			rtc_date.Date++;
			if(rtc_date.Date > 31) rtc_date.Date = 1;
			Unicode::snprintf(date_textBuffer, sizeof(date_textBuffer), "%02d", rtc_date.Date);
			//date_text.setWildcard1(date_textBuffer);
		} else if(month_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			rtc_date.Month++;
			if(rtc_date.Month > 12) rtc_date.Month = 1;
			Unicode::snprintf(month_textBuffer, sizeof(month_textBuffer), "%02d", rtc_date.Month);
			//date_text.setWildcard1(date_textBuffer);
		} else if(year_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			rtc_date.Year++;
			if(rtc_date.Year > 99) rtc_date.Year = 0;
			Unicode::snprintf(year_textBuffer, sizeof(year_textBuffer), "20%02d", rtc_date.Year);
			//date_text.setWildcard1(date_textBuffer);
		}
		flag_update_rtc = 1;
		box1.invalidate();
	}
	if(buttons_state == 0x08) {

		if(date_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(rtc_date.Date > 1) rtc_date.Date--;
			else rtc_date.Date = 31;
			Unicode::snprintf(date_textBuffer, sizeof(date_textBuffer), "%02d", rtc_date.Date);
			//date_text.setWildcard1(date_textBuffer);
		} else if(month_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(rtc_date.Month > 1) rtc_date.Month--;
			else rtc_date.Month = 12;
			Unicode::snprintf(month_textBuffer, sizeof(month_textBuffer), "%02d", rtc_date.Month);
			//date_text.setWildcard1(date_textBuffer);
		} else if(year_box.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(rtc_date.Year > 1) rtc_date.Year--;
			else rtc_date.Year = 99;
			Unicode::snprintf(year_textBuffer, sizeof(year_textBuffer), "20%02d", rtc_date.Year);
			//date_text.setWildcard1(date_textBuffer);
		}
		box1.invalidate();
	}
}
