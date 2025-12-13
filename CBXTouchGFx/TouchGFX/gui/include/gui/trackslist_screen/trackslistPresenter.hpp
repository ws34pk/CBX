#ifndef TRACKSLISTPRESENTER_HPP
#define TRACKSLISTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class trackslistView;

class trackslistPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    trackslistPresenter(trackslistView& v);

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

    virtual ~trackslistPresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    trackslistPresenter();

    trackslistView& view;
};

#endif // TRACKSLISTPRESENTER_HPP
