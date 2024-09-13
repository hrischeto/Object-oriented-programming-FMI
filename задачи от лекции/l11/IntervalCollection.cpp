#include "IntervalCollection.h"
#include <ostream>

IntervalCollection::IntervalCollection(int start, int end)
{
	if (end < start)
		std::swap(start, end);

	this->start = start;
	this->end = end;
	size = end - start;
	if (size >= capacity)
		resize(size);
}
unsigned IntervalCollection::intervalLength() const
{
	return end - start;
}

void IntervalCollection::add(int el)
{
	if (el < start || el > end)
		return;

	int index = el - start;
	data[index]++;	
}
void IntervalCollection::remove(int el)
{
	if (el < start || el > end)
	{
		return;
	}

	int index = el - start;

	if (data[index] == 0)
	{
		return;
	}

	--data[index];
}

int IntervalCollection::count(int el) const
{
	if (el < start || el > end)
		return 0;
	
	int index = el - start;
	return data[index];
}
bool IntervalCollection::contains(int el) const
{
	if (el < start || el > end)
		return 0;

	int index = el - start;
	return data[index];
}