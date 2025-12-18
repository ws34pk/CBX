#include <gui/containers/trackwheel.hpp>

extern "C" {
#include "main.h"
extern volatile uint8_t no_of_tracks;
extern volatile uint8_t tracks_list[MAX_NO_OF_TRACKS][MAX_TRACK_NAME_LENGTH];
}

trackwheel::trackwheel()
{

}

void trackwheel::initialize()
{
    trackwheelBase::initialize();
}

void trackwheel::setListElements(int item)
{
	/*
	static const char* names[10] =
	{
		"Apple",
		"Banana",
		"Cherry",
		"Dates",
		"Elderberry",
		"Fig",
		"Grapes",
		"Honeydew",
		"Indian Plum",
		"Jackfruit"
	};
	*/

	    //Unicode::snprintf(textArea1Buffer, 10, "%s", &tracks_list[item][0]);
		//Unicode::fromUTF8((const uint8_t*)names[item], textArea1Buffer, TEXTAREA1_SIZE);
		Unicode::fromUTF8((const uint8_t*)&tracks_list[item][0], textArea1Buffer, 15);
	    textArea1.invalidate();
}
