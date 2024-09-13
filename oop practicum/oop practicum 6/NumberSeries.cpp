#include "NumberSeries.h"
#include <iostream>

void NumberSeries::copyFrom(const NumberSeries& other)
{
	_a0 = other._a0;
	transFunc = other.transFunc;

	cacheSize = other.cacheSize;
	cache = new int[cacheSize];
	for (int i = 0;i < cacheSize;i++)
		cache[i] = other.cache[i];
}

void NumberSeries::free()
{
	_a0 = 0;
	cacheSize = 0;
	transFunc = nullptr;
	delete[] cache;
}

void NumberSeries::resize(size_t newSize)
{
	int* newData = new int[newSize];

	for (int i = 0;i < cacheSize;i++) 
		newData[i] = cache[i];

	delete[] cache;
	cache = newData;
	cacheSize = newSize;
}

NumberSeries::NumberSeries(int a0, int(*func)(int)):_a0(a0), transFunc(func)
{
	cache = nullptr;
	cacheSize = 0;
}

NumberSeries::NumberSeries(const NumberSeries& other)
{
	copyFrom(other);
}

NumberSeries& NumberSeries::operator=(const NumberSeries& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

NumberSeries::~NumberSeries()
{
	free();
}

void NumberSeries::setStartingPoint(int a0)
{
	_a0 = a0;
	delete[] cache;
	cacheSize = 0;
	cache = nullptr;
}

void NumberSeries::setTransitionFunction(int (*func)(int))
{
	transFunc = func;
	delete[] cache;
	cacheSize = 0;
	cache = nullptr;
}

bool NumberSeries::isPartOfSeries(int n) const
{
	for (int i = 0;i < cacheSize;i++)
	{
		if (cache[i] == n)
			return true;
	}
	return false;
}

int NumberSeries::getNumInPosition(size_t pos) 
{
	if (!cache)
	{
		cacheSize = pos +1;
		cache = new int[cacheSize] {_a0};
		for (int i = 1;i < cacheSize;i++)
			cache[i] = transFunc(cache[i - 1]);
	}

	if (pos >= cacheSize){
		size_t lastPos = cacheSize - 1;
		resize(pos+1);

		for (int i = lastPos+1;i < cacheSize;i++)
			cache[i] = transFunc(cache[i - 1]);
	}

	return cache[pos];
}

int main()
{
	NumberSeries mySeries(1, [](int n){ return n<<2; });
	std::cout << mySeries.getNumInPosition(9);
	mySeries.setStartingPoint(3);
	mySeries.setTransitionFunction([](int n) {return n + 1;});
	std::cout << mySeries.getNumInPosition(4) << std::endl;
	std::cout << mySeries.getNumInPosition(9) << std::endl << mySeries.getNumInPosition(2);
}