#include "MapKyes0ToN.h"
#include <iostream>
MapKeys0toN::MapKeys0toN(unsigned nullValue)
{
	_nullValue = nullValue;
	for (int i = 0;i < N;i++)
		_values[i] = _nullValue;
}

void MapKeys0toN::add(unsigned key, unsigned value)
{
	if (value == _nullValue || key >= N)
		return;
	_values[key] = value;
}

bool MapKeys0toN::contains(unsigned key) const
{
	if (key >= N)
		return false;

	return _values[key]!=_nullValue;
}

unsigned MapKeys0toN::getValue(unsigned key) const
{
		if (!contains(key))
			throw "Error";
		return _values[key];
}

unsigned fibb(unsigned n)
{
	if (n == 0 || n == 1)
		return 1;

	static MapKeys0toN cache(0);

	if (cache.contains(n))
		return cache.getValue(n);
	else
	{
		unsigned result = fibb(n - 1) + fibb(n - 2);
		cache.add(n, result);
		return result;
	}
}

int main()
{
	std::cout << fibb(30) << std::endl;
	std::cout << fibb(30);
}