#include "SortedCollection.h"
#include <iostream>

int SortedCollection::lowerBound(int el) const
{

	int left = 0;
	int right = size - 1;

	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] < el)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}
int SortedCollection::upperBound(int el) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] <= el)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int el)
{
	if (size == capacity)
		resize(capacity * 2);

	int ind = size;

	while (ind != 0 && data[ind - 1] > el)
	{
		data[ind] = data[ind - 1];
		ind--;
	}

	data[ind] = el;
	size++;
}

void SortedCollection::remove(int el)
{
	int elIndex = lowerBound(el);

	if (elIndex == size || data[elIndex] != el)
	{
		return;
	}

	for (int i = elIndex;i < size - 1;i++)
		data[i] = data[i + 1];

	size--;
}
int SortedCollection::count(int el) const
{
	int lower = lowerBound(el);

	if (lower == size || data[lower] != el)
	{
		return 0;
	}

	int upper = upperBound(el);

	return upper - lower;
}
bool SortedCollection::contains(int el) const
{
	int leftIndex = lowerBound(el);
	return leftIndex != size && data[leftIndex] == el;
}