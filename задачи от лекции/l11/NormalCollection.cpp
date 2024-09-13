#include "NormalCollection.h"
#include <iostream>

void NormalCollection::add(int el)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = el;
}
void NormalCollection::remove(int el)
{
	int ind = -1;

	for (int i = 0;i < size;i++)
	{
		if (data[i] == el)
		{
			ind = i;
			break;
		}
	}

	if (ind != -1)
	{
		std::swap(data[ind], data[size - 1]);
		size--;
	}

}
int NormalCollection::count(int el) const
{
	int count = 0;

	for (int i = 0;i < size;i++)
	{
		if (data[i] == el)
			count++;
	}

	return count;
}

bool NormalCollection::contains(int el) const
{

	for (int i = 0;i < size;i++)
	{
		if (data[i] == el)
			return true;
	}

	return false;
}
