#pragma once
#include "MyString.h"
class Device
{
public:
	virtual ~Device() = default;
	virtual Device* clone() const = 0;
	Device(const MyString& str, int price):name(str), price(price){}

protected:
	MyString name;
	int price = 0;
};