#ifndef NEWTRACK_1PRESENTER_HPP
#define NEWTRACK_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class newtrack_1View;

class newtrack_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    newtrack_1Presenter(newtrack_1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~newtrack_1Presenter() {}

private:
    newtrack_1Presenter();

    newtrack_1View& view;
};

#endif // NEWTRACK_1PRESENTER_HPP
