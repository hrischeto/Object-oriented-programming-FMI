#pragma once
#include "MyString.h"

enum class Location
{
	left, right, middle
};
class Control
{
protected:
	unsigned size;
	Location location;

public:
	Control(unsigned size, Location location):size(size), location(location){}
	virtual void setDataDialog() = 0;
	virtual ~Control()=default;
	virtual Control* clone()const = 0;
	size_t getSize() const { return size;}
	Location getLocaton() const { return location;}
	void setSize(unsigned newSize) { size = newSize; }
	void setLocation(Location newLocation) { location = newLocation;}
};