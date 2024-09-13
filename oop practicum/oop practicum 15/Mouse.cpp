#include "Mouse.h"

Device* Mouse::clone() const
{
	return new Mouse(*this);
}

Mouse::Mouse(const MyString& str, int price, double DPI) :Device(str, price), DPI(DPI) {}