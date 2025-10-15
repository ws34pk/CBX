#ifndef SET_DATEPRESENTER_HPP
#define SET_DATEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class set_dateView;

class set_datePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    set_datePresenter(set_dateView& v);

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

    virtual ~set_datePresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    set_datePresenter();

    set_dateView& view;
};

#endif // SET_DATEPRESENTER_HPP
