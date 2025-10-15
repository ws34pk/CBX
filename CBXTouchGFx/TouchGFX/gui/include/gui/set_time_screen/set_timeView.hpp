#ifndef SET_TIMEVIEW_HPP
#define SET_TIMEVIEW_HPP

#include <gui_generated/set_time_screen/set_timeViewBase.hpp>
#include <gui/set_time_screen/set_timePresenter.hpp>

class set_timeView : public set_timeViewBase
{
public:
    set_timeView();
    virtual ~set_timeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // SET_TIMEVIEW_HPP
