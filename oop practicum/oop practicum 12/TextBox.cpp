#include "TextBox.h"
TextBox::TextBox(unsigned size, Location location, const MyString& text):Control(size, location), text(text)
{

}
Control* TextBox::clone() const
{
	return new TextBox(*this);
}
void TextBox::setDataDialog()
{
	MyString newText;
	std::cin >> newText;
	text = newText;
}