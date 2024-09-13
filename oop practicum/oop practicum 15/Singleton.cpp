#include "Singleton.h"

bool Singleton::isElementIn(const Element& el) const
{
	return el.get(symbol);
}

SetExpression* Singleton::clone() const 
{
	return new Singleton(symbol);
}

Singleton::Singleton(char symbol):symbol(symbol){}

void Singleton::populateElements(Element& el) const
{
	el.set(symbol,1);
}
