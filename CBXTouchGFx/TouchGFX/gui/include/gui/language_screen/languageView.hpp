#ifndef LANGUAGEVIEW_HPP
#define LANGUAGEVIEW_HPP

#include <gui_generated/language_screen/languageViewBase.hpp>
#include <gui/language_screen/languagePresenter.hpp>

class languageView : public languageViewBase
{
public:
    languageView();
    virtual ~languageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void check_buttons(uint8_t buttons_state);
protected:
};

#endif // LANGUAGEVIEW_HPP
