#ifndef SET_DATEVIEW_HPP
#define SET_DATEVIEW_HPP

#include <gui_generated/set_date_screen/set_dateViewBase.hpp>
#include <gui/set_date_screen/set_datePresenter.hpp>

class set_dateView : public set_dateViewBase
{
public:
    set_dateView();
    virtual ~set_dateView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // SET_DATEVIEW_HPP
