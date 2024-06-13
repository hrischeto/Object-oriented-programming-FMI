#pragma once
#include <iostream>
#include "MyString.h"

class Ticket 
{
public:
	Ticket();
	Ticket(const MyString& data, double price);
private:
	MyString play;
	double price;
};