#pragma once
#include "bitset.h"

class SetByCriteria:private Bitset
{public:
	SetByCriteria(unsigned maxNum, bool(*func)(int num));
	unsigned getSize() const;
	using Bitset::contains;
	using Bitset::print;

private:
	bool (*criteria)(int num);

	void fillSet();
};

