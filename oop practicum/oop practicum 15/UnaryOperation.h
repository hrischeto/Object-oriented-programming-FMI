#pragma once
#include "SetExpression.h"
class UnaryOperation : public SetExpression
{
public:
	UnaryOperation(SetExpression* set, char operation);
	~UnaryOperation();

	SetExpression* clone() const override;
	bool isElementIn(const Element& el) const override;

	void populateElements(Element& el) const override;


protected: 
	char operation;
	SetExpression* set;
};

