#include <iostream>
#include "StudentTicket.h"

StudentTicket::StudentTicket(const MyString& data, double originalPrice) :Ticket(data, originalPrice / 2)
{}