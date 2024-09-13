#include "assert.h"
#include "MyString.h"
#include "stringView.h"

struct SetExpression
{
public:
	struct Element
	{
		bool sets[26] = { false };

		void set(char ch, bool isIn)
		{
			assert(ch >= 'A' && ch <= 'Z');
			sets[ch - 'A'] = isIn;
		}
		bool get(char ch) const
		{
			assert(ch >= 'A' && ch <= 'Z');
			return sets[ch - 'A'];
		}
	};

	virtual bool isElementIn(const Element& el) const = 0;
	virtual ~SetExpression()=default;
	virtual void populateVariables

protected:
	Element el;
};

struct Singleton :public SetExpression
{
	bool isElementIn(const Element& el) const override
	{
		return el.get(ch);
	}

	Singleton(char ch) :ch(ch) {}
private:
	char ch;
};

struct UnaryOperation :SetExpression
{
	UnaryOperation(char op, SetExpression* expr) :expr(expr), op(op) {}
	bool isElementIn(const Element& el) const override
	{
		if (op == '!')
			return !expr->isElementIn(el);

		return false;
	}
private:
	char op;
	SetExpression* expr;
};

struct BinaryOperation :SetExpression
{
	BinaryOperation(SetExpression* left, SetExpression* right, char op):left(left), right(right), op(op){}

	bool isElementIn(const Element& el) const override
	{
		switch (op)
		{
		case 'v':
			return left->isElementIn(el) || right->isElementIn(el);
		case '^':
			return left->isElementIn(el) && right->isElementIn(el);
		case '\\':
			return left->isElementIn(el) && (! right->isElementIn(el));
		case 'x':
			return (!(left->isElementIn(el) && right->isElementIn(el)))&&(left->isElementIn(el)||right->isElementIn(el));
		default:
			return false;
		}
	}

private:
	SetExpression* left;
	SetExpression* right;
	char op;
};

static SetExpression* setFactory(StringView str)
{
	str = str.substr(1, str.length() - 1);

	if (str.length() == 1)
		return new Singleton(str[0]);

	unsigned len = str.length();
	unsigned count = 0;

	for (int i = 0;i < len;i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		else if (count == 0)
		{
			switch (str[i])
			{
			case '!':
				return new UnaryOperation('!', setFactory(str.substr(i + 1, len- i - 1)));
			case 'v':
				return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, len - i - 1)), 'v');
			case '^':
				return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, len - i - 1)), '^');
			case '\\':
				return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, len - i - 1)), '\\');
			case 'x':
				return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, len - i - 1)), 'x');
			}
		}
	}

	throw std::invalid_argument("invalid expression");
}

class SetCalculator
{
	SetExpression* expr;
	SetExpression::Element elements;

public:
	SetCalculator(const MyString& str)
	{
		expr = setFactory(str);
	}
	
};