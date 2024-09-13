#pragma once
#include "SetExpression.h"
#include "MyString.h"
class SetExpressionHandler
{
public:
	SetExpressionHandler(MyString str);
	SetExpressionHandler(const SetExpressionHandler& other);
	SetExpressionHandler(SetExpressionHandler&& other);
	SetExpressionHandler& operator=(const SetExpressionHandler& other);
	SetExpressionHandler& operator=(SetExpressionHandler&& other);
	~SetExpressionHandler();

private:
	void copyFrom(const SetExpressionHandler& other);
	void moveFrom(SetExpressionHandler&& other);
	void free();

	SetExpression* expr;
	SetExpression::Element elements;
};

