#ifndef NEWTRACKVIEW_HPP
#define NEWTRACKVIEW_HPP

#include <gui_generated/newtrack_screen/newtrackViewBase.hpp>
#include <gui/newtrack_screen/newtrackPresenter.hpp>

class newtrackView : public newtrackViewBase
{
public:
    newtrackView();
    virtual ~newtrackView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // NEWTRACKVIEW_HPP
