#pragma once
#include "Ticket.h"
#include "MyString.h"
class GroupTicket : public Ticket
{
public:
	GroupTicket(const MyString& data, double originalPrice);
};

