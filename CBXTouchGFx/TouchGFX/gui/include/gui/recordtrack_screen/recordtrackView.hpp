#ifndef RECORDTRACKVIEW_HPP
#define RECORDTRACKVIEW_HPP

#include <gui_generated/recordtrack_screen/recordtrackViewBase.hpp>
#include <gui/recordtrack_screen/recordtrackPresenter.hpp>

class recordtrackView : public recordtrackViewBase
{
public:
    recordtrackView();
    virtual ~recordtrackView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // RECORDTRACKVIEW_HPP
