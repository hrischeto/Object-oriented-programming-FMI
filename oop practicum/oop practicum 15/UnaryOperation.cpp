#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(SetExpression* set, char operation):set(set), operation(operation){}

UnaryOperation::~UnaryOperation()
{
	delete set;
}

SetExpression* UnaryOperation::clone() const
{
	return new UnaryOperation(set->clone(), operation);
}

bool UnaryOperation::isElementIn(const Element& el) const
{
	if (operation == '!')
		return !(set->isElementIn(el));
}

void UnaryOperation::populateElements(Element& el) const
{
	set->populateElements(el);

	if (operation == '!')
	{
		for (char i = 'A';i <= 'Z';i++)
		{
			if (el.sets[i - 'A'])
				el.set(i, 0);
			else
				el.set(i, 1);
		}
	}
}
