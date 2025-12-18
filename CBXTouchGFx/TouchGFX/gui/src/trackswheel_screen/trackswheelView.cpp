#include <gui/trackswheel_screen/trackswheelView.hpp>

extern "C"{
extern volatile uint8_t no_of_tracks;
extern volatile uint8_t selected_track_index;
}

trackswheelView::trackswheelView()
{
	//scrollWheel1.setNumberOfItems(no_of_tracks);
}

void trackswheelView::setupScreen()
{
	if(no_of_tracks) {
		//scrollWheel1.setMaxSwipeItems(no_of_tracks);
		scrollWheel1.setNumberOfItems(no_of_tracks);
		scrollWheel1.invalidate();
	}
	trackswheelViewBase::setupScreen();
}

void trackswheelView::tearDownScreen()
{
    trackswheelViewBase::tearDownScreen();
}

void trackswheelView::scrollWheel1UpdateItem(trackwheel& item, int16_t itemIndex)
{
    item.setListElements(itemIndex);
}

void trackswheelView::scrollWheel1UpdateCenterItem(CustomContainer2& item, int16_t itemIndex)
{
	item.setListElements(itemIndex);
}

void trackswheelView::check_buttons(uint8_t buttons_state)
{
	//return to the main screen
	if(buttons_state == 0x01)
		static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();

	if(buttons_state == 0x02)
		selected_track_index = scrollWheel1.getSelectedItem();

	if(buttons_state == 0x04) {
		scrollUp();
	}

	if(buttons_state == 0x08) {
		scrollDown();
	}
}

void trackswheelView::scrollUp()
{
    if (selectedIndex > 0)
    {
        selectedIndex--;
        scrollWheel1.invalidate();
        scrollWheel1.animateToItem(selectedIndex, no_of_tracks);
        //box1.invalidate();
    }
}

void trackswheelView::scrollDown()
{
    if (selectedIndex < 9)    // last index
    {
        selectedIndex++;
        scrollWheel1.invalidate();
        scrollWheel1.animateToItem(selectedIndex, no_of_tracks);
        //box1.invalidate();
    }
}


