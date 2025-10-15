#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

extern "C" {
extern uint8_t no_of_tracks;
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x02) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			if(no_of_tracks)
				static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
			else
				static_cast<FrontendApplication*>(Application::getInstance())->gotonewtrackScreenNoTransition();
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
		}
		else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen3ScreenNoTransition();
		else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen6ScreenNoTransition();
		else if(box6.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotosettingsScreenNoTransition();

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
			box6.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}	else if(box6.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
			//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
		if(buttons_state == 0x08) {
			if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box6.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box6.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box5.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			}
			box1.invalidate();
		}
			/*
	if(buttons_state == 0x02) {
	if(no_of_tracks)
		static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	else
		static_cast<FrontendApplication*>(Application::getInstance())->gotonewtrackScreenNoTransition();

		}
		*/
}
