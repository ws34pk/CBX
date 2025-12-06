#ifndef ADDNEWTRACKVIEW_HPP
#define ADDNEWTRACKVIEW_HPP

#include <gui_generated/addnewtrack_screen/addnewtrackViewBase.hpp>
#include <gui/addnewtrack_screen/addnewtrackPresenter.hpp>

class addnewtrackView : public addnewtrackViewBase
{
public:
    addnewtrackView();
    virtual ~addnewtrackView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // ADDNEWTRACKVIEW_HPP
