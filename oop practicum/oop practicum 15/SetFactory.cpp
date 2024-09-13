#include "SetFactory.h"

SetExpression* setFactory(StringView str)
{
	str = str.substr(1, str.length() - 2);

	if (str.length() == 1)
		return new Singleton(str[0]);

	unsigned count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		else if (count == 0)
		{
			switch (str[i])
			{
			case 'v': return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.length() - i - 1)), 'v');
			case '^': return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.length() - i - 1)), '^');
			case '\\': return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.length() - i - 1)), '\\');
			case 'x': return new BinaryOperation(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.length() - i - 1)), 'x');
			case '!': return new UnaryOperation(setFactory(str.substr(i+1,str.length()-i-1)), '!');
			}
			
		}
	}

	throw std::invalid_argument("Invalid expression!");
}