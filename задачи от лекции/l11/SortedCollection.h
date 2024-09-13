#pragma once
#include "PureNumbersCollection.h"

class SortedCollection :public PureNumbersCollection
{
	int lowerBound(int el) const;
	int upperBound(int el) const;
public:
	void add(int el);
	void remove(int el);
	int count(int el) const;
	bool contains(int el) const;
};

