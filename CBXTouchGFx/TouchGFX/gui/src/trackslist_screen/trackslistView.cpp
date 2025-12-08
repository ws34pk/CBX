#include <gui/trackslist_screen/trackslistView.hpp>

trackslistView::trackslistView()
{

}

void trackslistView::setupScreen()
{
    trackslistViewBase::setupScreen();

    // Configure ScrollList
	//scrollList1.setNumberOfItems(10);
	//scrollList1.setUpdateItemCallback(updateItemCallback);
}

void trackslistView::tearDownScreen()
{
    trackslistViewBase::tearDownScreen();
}

void trackslistView::scrollList1UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.setListElements(itemIndex);
}

