#include "SetExpressionHandler.h"
#include "SetFactory.h"
SetExpressionHandler::SetExpressionHandler(MyString str)
{
	expr = setFactory(str);
	expr->populateElements(elements);
}
SetExpressionHandler::SetExpressionHandler(const SetExpressionHandler& other)
{
	copyFrom(other);
}
SetExpressionHandler::SetExpressionHandler(SetExpressionHandler&& other)
{
	moveFrom(std::move(other));
}
SetExpressionHandler& SetExpressionHandler::operator=(const SetExpressionHandler& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SetExpressionHandler& SetExpressionHandler::operator=(SetExpressionHandler&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SetExpressionHandler::~SetExpressionHandler()
{
	free();
}


void SetExpressionHandler::copyFrom(const SetExpressionHandler& other)
{
	expr = other.expr->clone();
	elements = other.elements;
}
void SetExpressionHandler::moveFrom(SetExpressionHandler&& other)
{
	expr = other.expr;
	other.expr = nullptr;

	elements = other.elements;
}
void SetExpressionHandler::free()
{
	delete expr;

}
