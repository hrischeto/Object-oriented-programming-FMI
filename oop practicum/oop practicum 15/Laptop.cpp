#include "Laptop.h"

Device* Laptop::clone() const
{
	return new Laptop(*this);
}

Laptop::Laptop(const MyString& str, int price, double weight) :Device(str, price), weight(weight) {}