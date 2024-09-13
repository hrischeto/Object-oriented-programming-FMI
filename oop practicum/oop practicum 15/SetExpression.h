#pragma once
#include <assert.h>

constexpr size_t SET_MAX_SIZE = 26;
class SetExpression
{
public:
	struct Element
	{
		bool sets[SET_MAX_SIZE] = { false };

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
	virtual SetExpression* clone() const = 0;
	virtual ~SetExpression() = default;
	SetExpression() = default;

	SetExpression(const SetExpression& other) = delete;
	SetExpression operator=(const SetExpression& other) = delete;
	
	virtual void populateElements(Element& el) const = 0;

};

