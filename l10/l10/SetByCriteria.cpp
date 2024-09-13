#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned maxNum, bool(*func)(int num)):Bitset(maxNum), criteria(func)
{
	fillSet();
}

unsigned SetByCriteria::getSize() const
{
	unsigned max = getN();
	int count = 0;
	for (int i = 0;i <= max;i++)
	{
		if (contains(i))
			count++;
	}
	return count;
}

void SetByCriteria::fillSet()
{
	unsigned max = getN();
	for (int i = 0;i <=max;i++)
	{
		if (criteria(i))
			add(i);
	}
}