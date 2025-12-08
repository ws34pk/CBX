#include <gui/containers/CustomContainer1.hpp>

CustomContainer1::CustomContainer1()
{

}

void CustomContainer1::initialize()
{
    CustomContainer1Base::initialize();
    textArea1.setWildcard(textArea1Buffer);
}

void CustomContainer1::setListElements(int item)
{
	/*
	switch(item)
	{
	case 0:
		textArea1.setTypedText();
		break;
	case 1:
		textArea1.setTypedText();
		break;
	case 2:
		textArea1.setTypedText();
		break;
	case 3:
		textArea1.setTypedText();
		break;
	case 4:
		textArea1.setTypedText();
		break;
	case 5:
		textArea1.setTypedText();
		break;
	case 6:
		textArea1.setTypedText();
		break;
	case 7:
		textArea1.setTypedText();
		break;
	case 8:
		textArea1.setTypedText();
		break;
	case 9:
		textArea1.setTypedText();
		break;
	case 10:
		textArea1.setTypedText();
		break;
	default:
		break;

	}
	*/
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
	    //textArea1.invalidate();
		box1.invalidate();
}
