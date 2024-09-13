#include "PC.h"

Device* PC::clone() const
{
	return new PC(*this);
}

PC::PC(const MyString& str, int price) :Device(str, price){}
