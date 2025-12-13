#ifndef TRACKSWHEELVIEW_HPP
#define TRACKSWHEELVIEW_HPP

#include <gui_generated/trackswheel_screen/trackswheelViewBase.hpp>
#include <gui/trackswheel_screen/trackswheelPresenter.hpp>

class trackswheelView : public trackswheelViewBase
{
public:
    trackswheelView();
    virtual ~trackswheelView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheel1UpdateItem(trackwheel& item, int16_t itemIndex);
    virtual void scrollWheel1UpdateCenterItem(CustomContainer2& item, int16_t itemIndex);

    void scrollUp();
	void scrollDown();
	virtual void check_buttons(uint8_t buttons_state);

	volatile int16_t selectedIndex;
    //virtual void scrollWheelUpdateCenterItem(CustomContainer2& item, int16_t itemIndex);
protected:
};

#endif // TRACKSWHEELVIEW_HPP
