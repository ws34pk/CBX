#include <gui/containers/CustomContainer2.hpp>

CustomContainer2::CustomContainer2()
{

}

void CustomContainer2::initialize()
{
    CustomContainer2Base::initialize();
}


void CustomContainer2::setListElements(int item)
{
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

	    //Unicode::snprintf(textBuffer, 32, "%s", names[item]);
		Unicode::fromUTF8((const uint8_t*)names[item], textArea1Buffer, TEXTAREA1_SIZE);
	    textArea1.invalidate();
}
