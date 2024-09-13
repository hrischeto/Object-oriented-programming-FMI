#include "Order.h"

Order::Order(const MyString& restaurante, int prCount):products(prCount),restaurante(restaurante), prCount(prCount)
{}

void Order::addProduct(MyString pr)
{
	products.push_back(pr);
}

int Order::minutesForDelivery() const
{
	int res = prCount;
	for (int i = 0;i < prCount;i++)
	{
		res += products[i].getSize();
	}

	return res;
}

const MyString& Order::getRestaurante() const
{
	return restaurante;
}

const StringVector& Order::getProductList() const
{
	return products;
}
int Order::getProductsCount() const
{
	return prCount;
}
int main()
{
	Order myOrder("pizzaPlace", 3);
	myOrder.addProduct("mozzarella");
	myOrder.addProduct("tomatoes");
	myOrder.addProduct("pepperoni");
	std::cout << myOrder.getRestaurante() << std::endl;
	for(int i=0;i<3;i++)
		std::cout << myOrder.getProductList()[i].c_str() << std::endl;
}