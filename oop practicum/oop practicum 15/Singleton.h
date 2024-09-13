#pragma once
#include "SetExpression.h"
class Singleton : public SetExpression
{
public:
	bool isElementIn(const Element& el) const override;
	SetExpression* clone() const override;
	Singleton(char symbol);

	void populateElements(Element& el) const override;

private:
	char symbol;
};

