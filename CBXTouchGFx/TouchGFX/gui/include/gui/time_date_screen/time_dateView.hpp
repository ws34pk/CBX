#ifndef TIME_DATEVIEW_HPP
#define TIME_DATEVIEW_HPP

#include <gui_generated/time_date_screen/time_dateViewBase.hpp>
#include <gui/time_date_screen/time_datePresenter.hpp>

class time_dateView : public time_dateViewBase
{
public:
    time_dateView();
    virtual ~time_dateView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // TIME_DATEVIEW_HPP
