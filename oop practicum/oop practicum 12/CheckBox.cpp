#include "CheckBox.h"

CheckBox::CheckBox(unsigned size, Location location, const MyString& text):Control(size, location), state(0), text(text){}
Control* CheckBox::clone() const
{
	return new CheckBox(*this);
}
void CheckBox::setDataDialog()
{
	std::cin >> state;
}

void CheckBox::setText(const MyString& newText)
{
	text = newText;
}
