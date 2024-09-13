#pragma once
#include "StringVector.h"
class Order
{
public:
	Order() = default;
	Order(const MyString& restaurante, int prCount);
	void addProduct(MyString pr);
	int minutesForDelivery() const;

	const MyString& getRestaurante() const;
	const StringVector& getProductList() const;
	int getProductsCount() const;
private:

	MyString restaurante;
	StringVector products;
	size_t prCount;
};

