#ifndef TRACKSLISTVIEW_HPP
#define TRACKSLISTVIEW_HPP

#include <gui_generated/trackslist_screen/trackslistViewBase.hpp>
#include <gui/trackslist_screen/trackslistPresenter.hpp>

class trackslistView : public trackslistViewBase
{
public:
    trackslistView();
    virtual ~trackslistView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollList1UpdateItem(CustomContainer1& item, int16_t index);
    //void updateListItem(CustomContainer1& item, int16_t index);

protected:
    Callback<trackslistView, int16_t> scrollList1_ItemSelectedCallback;
    void scrollList_ItemSelectedHandler(int16_t ItemSelected);
};

#endif // TRACKSLISTVIEW_HPP
