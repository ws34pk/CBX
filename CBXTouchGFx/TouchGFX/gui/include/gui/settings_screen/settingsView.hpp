#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <gui_generated/settings_screen/settingsViewBase.hpp>
#include <gui/settings_screen/settingsPresenter.hpp>

class settingsView : public settingsViewBase
{
public:
    settingsView();
    virtual ~settingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // SETTINGSVIEW_HPP
