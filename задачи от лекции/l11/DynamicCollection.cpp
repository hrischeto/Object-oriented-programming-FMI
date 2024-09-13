#include "DynamicCollection.h"
#include <iostream>

void DynamicCollection::copyFrom(const DynamicCollection& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}
void DynamicCollection::moveFrom(DynamicCollection&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}
void DynamicCollection::free()
{
	delete[] data;
}
void DynamicCollection::resize(size_t newCap)
{
	int* newData = new int[newCap];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCap;
}

DynamicCollection::DynamicCollection(size_t capacity):capacity(capacity), size(0)
{
	data = new int[capacity];
}


DynamicCollection::DynamicCollection():capacity(8), size(0)
{
	data = new int[capacity];

}

DynamicCollection::DynamicCollection(const DynamicCollection& other)
{
	copyFrom(other);
}
DynamicCollection::DynamicCollection(DynamicCollection&& other) noexcept
{
	moveFrom(std::move(other));
}
DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
DynamicCollection::~DynamicCollection()
{
	free();
}
