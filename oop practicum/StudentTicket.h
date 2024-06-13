#pragma once
#include "Ticket.h"
#include "MyString.h"
class StudentTicket : public Ticket
{
public: 
	StudentTicket(const MyString& data, double originalPrice);
};

