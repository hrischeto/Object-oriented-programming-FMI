#include <iostream>
#include "Ticket.h"

Ticket::Ticket(const MyString& data, double price) : play(data)
{
	this->price = price;
}

Ticket::Ticket() :Ticket("undefined", 0)
{}