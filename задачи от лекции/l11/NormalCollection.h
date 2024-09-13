#pragma once
#include "PureNumbersCollection.h"

class NormalCollection : public PureNumbersCollection
{
public:
	void add(int el) override;
	void remove(int el) override;
	int count(int el) const override;
	bool contains(int el) const override;

};
