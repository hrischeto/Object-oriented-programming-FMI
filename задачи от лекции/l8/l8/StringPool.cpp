#include "StringPool.h"
#include <iostream>
#pragma warning (disable:4996)

StringPool::StringPool()
{
	stringCount = 0;
	stringCapacity = 2;

	stringRecords = new StringRecord[stringCapacity];
}

StringPool::~StringPool()
{
	for (int i = 0;i < stringCapacity;i++)
		delete[] stringRecords[i].str;

	delete[] stringRecords;
}

const char* StringPool::getAllocatedString(const char* str)
{
	int index = findAllocatedString(str);

	if (index != -1)
	{
		stringRecords[index].refCount++;
		return stringRecords[index].str;
	}
	else
	{
		index = allocatedNewString(str);
		stringRecords[index].refCount++;
		return stringRecords[index].str;
	}
}

void StringPool::releaseString(const char* str)
{
	int index = findAllocatedString(str);

	if (index != -1)
	{
		stringRecords[index].refCount--;
		if (stringRecords[index].refCount == 0)
			removeRecord(index);
	}
}

unsigned StringPool::allocatedNewString(const char* str)
{
	if (stringCount == stringCapacity)
		resize(stringCapacity * 2);

	int firstFreeIndex = stringCount++;

	stringRecords[firstFreeIndex].str = new char[std::strlen(str)+1];
	std::strcpy(stringRecords[firstFreeIndex].str, str);
	stringRecords[firstFreeIndex].refCount = 0;

	return firstFreeIndex;
}

void StringPool::resize(size_t newCap)
{
	StringRecord* newData = new StringRecord[newCap];

	for (int i = 0;i < stringCount;i++)
	{
		newData[i] = stringRecords[i];
	}

	delete[] stringRecords;

	stringRecords = newData;

	stringCapacity = newCap;
}

int StringPool::findAllocatedString(const char* str) const
{
	for (int i = 0; i < stringCount; i++)
	{
		if (std::strcmp(str, stringRecords[i].str) == 0)
			return i;
	}
	return -1;
}

void StringPool::removeRecord(unsigned index)
{
	std::swap(stringRecords[index], stringRecords[stringCount - 1]);
	
	delete[] stringRecords[stringCount - 1].str;
	stringRecords[stringCount - 1].str = nullptr;
	stringRecords[stringCount--].refCount = 0;
}
