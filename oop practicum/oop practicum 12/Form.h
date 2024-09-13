#pragma once
#include "ControlContainer.h"

class Form
{
public:
	void setSize(size_t newLength, size_t newWidth);
	Form(size_t length, size_t width);

private:
	unsigned length = 0;
	unsigned width = 0;
	MyString name;

	ControlContainer controls;
};

