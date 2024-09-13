#pragma once
#include "StringVector.h"
#include "Order.h"
class Restaurant
{
public:
	void addProduct(const MyString& product);
	void recieveOrder(const Order& order);


private:
	char Name[25];
	StringVector products;
};

