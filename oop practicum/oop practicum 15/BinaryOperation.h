#pragma once
#include "SetExpression.h"
class BinaryOperation : public SetExpression
{
public:
	BinaryOperation(SetExpression* left, SetExpression* right, char operation);
	~BinaryOperation();

	SetExpression* clone() const override;
	bool isElementIn(const Element& el) const override;

	void populateElements(Element& el) const override;


protected:
	char operation;
	SetExpression* left;
	SetExpression* right;
};

