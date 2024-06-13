#include "GroupTicket.h"

#include <iostream>

GroupTicket::GroupTicket(const MyString& data, double originalPrice) : Ticket(data, originalPrice-originalPrice*0.2)
{

}


int main()
{
	GroupTicket obj("abc", 10);
}