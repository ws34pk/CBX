#ifndef NEWTRACK_1VIEW_HPP
#define NEWTRACK_1VIEW_HPP

#include <gui_generated/newtrack_1_screen/newtrack_1ViewBase.hpp>
#include <gui/newtrack_1_screen/newtrack_1Presenter.hpp>

class newtrack_1View : public newtrack_1ViewBase
{
public:
    newtrack_1View();
    virtual ~newtrack_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // NEWTRACK_1VIEW_HPP
