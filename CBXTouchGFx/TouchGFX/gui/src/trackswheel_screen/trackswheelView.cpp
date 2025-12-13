#include <gui/trackswheel_screen/trackswheelView.hpp>

trackswheelView::trackswheelView()
{

}

void trackswheelView::setupScreen()
{
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
        scrollWheel1.animateToItem(selectedIndex, 10);
        //box1.invalidate();
    }
}

void trackswheelView::scrollDown()
{
    if (selectedIndex < 9)    // last index
    {
        selectedIndex++;
        scrollWheel1.invalidate();
        scrollWheel1.animateToItem(selectedIndex, 10);
        //box1.invalidate();
    }
}


