#include <gui/trackslist_screen/trackslistView.hpp>

trackslistView::trackslistView()
{

}

void trackslistView::setupScreen()
{
    trackslistViewBase::setupScreen();

    // Configure ScrollList
	scrollList1.setNumberOfItems(10);
	//scrollList1.setUpdateItemCallback(updateItemCallback);
}

void trackslistView::tearDownScreen()
{
    trackslistViewBase::tearDownScreen();
}

void trackslistView::scrollList1UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.setListElements(itemIndex);
	//item.setHighlighted(itemIndex == selectedIndex);
}


// function to be called every time an item is selected
void trackslistView::scrollList_ItemSelectedHandler(int16_t itemSelected){

    switch(itemSelected){

        case 0:
            // code for item 0

            break;
        case 1:
            // code for item 1
            break;
    }
}

void trackslistView::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x04) {
		scrollUp();
	}

	if(buttons_state == 0x08) {
		scrollDown();
	}
}

void trackslistView::scrollUp()
{
    if (selectedIndex > 0)
    {
        selectedIndex--;
        scrollList1.invalidate();
        scrollList1.animateToItem(selectedIndex, 10);  // smooth scrolling
        //box1.invalidate();
    }
}

void trackslistView::scrollDown()
{
    if (selectedIndex < 9)    // last index
    {
        selectedIndex++;
        scrollList1.invalidate();
        scrollList1.animateToItem(selectedIndex, 10);
        //box1.invalidate();
    }
}


