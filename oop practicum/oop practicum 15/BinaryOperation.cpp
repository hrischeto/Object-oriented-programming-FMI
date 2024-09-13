#include "BinaryOperation.h"
#include <iostream>

BinaryOperation::BinaryOperation(SetExpression* left, SetExpression* right, char operation) 
								:left(left), right(right),operation(operation) {}

BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}

SetExpression* BinaryOperation::clone() const
{
	return new BinaryOperation(left->clone(), right->clone(), operation);
}

bool BinaryOperation::isElementIn(const Element& el) const
{
	switch (operation) 
	{
	case 'v':
		return left->isElementIn(el) || right->isElementIn(el);
	case '^':
		return left->isElementIn(el) && right->isElementIn(el);
	case '\\':
		return (!left->isElementIn(el)) && right->isElementIn(el);
	case 'x':
		return !(left->isElementIn(el) && right->isElementIn(el))&&(left->isElementIn(el)||right->isElementIn(el));
	default:
		throw std::invalid_argument("Invalid operation!");
	}
	
}

void BinaryOperation::populateElements(Element& el) const
{
	Element leftElements;
	Element rightElements;
	left->populateElements(leftElements);
	right->populateElements(rightElements);

	switch (operation)
	{
	case 'v':
		for (char i = 'A';i <= 'Z';i++)
		{
			if (leftElements.sets[i - 'A'] || rightElements.sets[i - 'A'])
				el.set(i, 1);
		}
		break;

	case '^':
		for (char i = 'A';i <= 'Z';i++)
		{
			if (leftElements.sets[i - 'A'] && rightElements.sets[i - 'A'])
				el.set(i, 1);
		}
		break;
	case '\\':
		for (char i = 'A';i <= 'Z';i++)
		{
			if (!leftElements.sets[i - 'A'] && rightElements.sets[i - 'A'])
				el.set(i, 1);
		}
		break;
	case 'x':
		for (char i = 'A';i <= 'Z';i++)
		{
			if (!(leftElements.sets[i - 'A'] && rightElements.sets[i - 'A']) && (leftElements.sets[i - 'A'] || rightElements.sets[i - 'A']))
				el.set(i, 1);
		}
		break;
	default:
		throw std::invalid_argument("Invalid operation!");
	}
}
