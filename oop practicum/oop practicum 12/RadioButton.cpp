#include "RadioButton.h"

RadioButton::RadioButton(unsigned size, Location location, size_t optionsCount) :Control(size, location), count(optionsCount)
{
	options = new MyString[count];

	for (int i = 0;i < count;i++)
	{
		std::cin >> options[i];
	}
	chosenOption = -1;
}
Control* RadioButton::clone() const
{
	return new RadioButton(*this);
}
void RadioButton::setDataDialog()
{
	std::cin >> chosenOption;
}
void RadioButton::setOptionNameAtIndex(const MyString& newText, size_t index)
{
	if (index >= count)
		throw std::out_of_range("Invalid index");

	std::cin >> options[index];
}

RadioButton::RadioButton(const RadioButton& other):Control(other), count(other.count)
{
	copyFrom(other);
}
RadioButton::RadioButton(RadioButton&& other)noexcept :Control(std::move(other)), count(other.count)
{
	moveFrom(std::move(other));
}


RadioButton& RadioButton::operator=(const RadioButton& other)
{
	if (this != &other)
	{
		Control::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
RadioButton& RadioButton::operator=(RadioButton&& other)
{
	if (this != &other)
	{
		Control::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
RadioButton::~RadioButton()
{
	free();
}

void RadioButton::free()
{
	delete[] options;
}
void RadioButton::copyFrom(const RadioButton& other)
{
	for (int i = 0;i < count;i++)
	{
		options[i] = other.options[i];
	}

	chosenOption = other.chosenOption;
}
void RadioButton::moveFrom(RadioButton&& other)
{
	options = other.options;
	other.options = nullptr;

	chosenOption = other.chosenOption;
	other.chosenOption = -1;
}