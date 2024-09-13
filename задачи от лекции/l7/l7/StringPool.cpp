#include "StringPool.h"
#pragma warning (disable:4996)

static bool isValidChar(char ch)
{
	return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9';
}

static bool isValidString(const char* str)
{
	while (*str)
	{
		if (!isValidChar(*str))
			return false;
		str++;
	}
	return true;
}

StringPool::StringPool()
{
	stringCount = 0;
	stringCapacity = 2;

	stringRecords = new StringRecord[stringCapacity];
}

StringPool::StringPool(const StringPool& other)
{
	copyFrom(other);
}

StringPool& StringPool::operator=(const StringPool& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

StringPool::~StringPool()
{
	free();
}

void StringPool::free()
{
	for (int i = 0;i < stringCapacity;i++)
		delete[] stringRecords[i].str;

	delete[] stringRecords;
}

void StringPool::copyFrom(const StringPool& other)
{
	stringCount = other.stringCount;
	stringCapacity = other.stringCapacity;
	for (int i = 0;i < stringCount;i++)
	{
		size_t size = std::strlen(other.stringRecords[i].str);
		stringRecords[i].str = new char [size];
		strcpy(stringRecords[i].str, other.stringRecords[i].str);
		stringRecords[i].refCount = other.stringRecords[i].refCount;
	}
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
		if (index == -1)
			throw std::invalid_argument("Invalid characters in string!");
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
	if (!isValidString(str))
		return -1;
	if (stringCount == stringCapacity)
		resize(stringCapacity * 2);

	int firstFreeIndex = stringCount++;

	stringRecords[firstFreeIndex].str = new char[std::strlen(str) + 1];
	std::strcpy(stringRecords[firstFreeIndex].str, str);
	stringRecords[firstFreeIndex].refCount = 0;
	sort();

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
	unsigned left = 0;
	unsigned right = stringCount - 1;

	while(left<=right)
	{
		unsigned mid = left + (right - left) / 2;
		if (std::strcmp(str, stringRecords[mid].str) > 0)
		{
			left = mid + 1;
		}
		else if (std::strcmp(str, stringRecords[mid].str) < 0)
			right = mid - 1;
		else
			return mid;
	}

	return -1;
}

void StringPool::removeRecord(unsigned index)
{
	std::swap(stringRecords[index], stringRecords[stringCount - 1]);
	
	delete[] stringRecords[stringCount - 1].str;
	stringRecords[stringCount - 1].str = nullptr;
	stringRecords[stringCount--].refCount = 0;
	sort();
}

void StringPool::sort()
{
	for (int i = 0;i < stringCount - 1;i++)
	{
		int minElIndex = i;

		for (int j = i + 1; j < stringCount;j++)
		{
			if (std::strcmp(stringRecords[minElIndex].str, stringRecords[j].str) > 0)
				minElIndex = j;
		}

		if (minElIndex != i)
			std::swap(stringRecords[minElIndex], stringRecords[i]);

	}
}

StringPool& StringPool::operator+=(const StringPool& other)
{
	for (int i = 0;i < other.stringCount;i++)
	{
		unsigned index = findAllocatedString(other.stringRecords[i].str);

		if (index != -1)
			stringRecords[index].refCount += other.stringRecords[i].refCount;
		else
		{
			if (stringCount == stringCapacity)
				resize(stringCapacity * 2);
			stringRecords[stringCount] = other.stringRecords[i];
		}
			
	}
	sort();
	return *this;
}

StringPool& StringPool::operator-=(const StringPool& other)
{
	for (int i = 0;i < other.stringCount;i++)
	{
		unsigned index = findAllocatedString(other.stringRecords[i].str);
		if (index != -1)
			removeRecord(index);
	}
	return *this;
}

bool StringPool::operator[](const char* str) const
{
	return findAllocatedString(str) != -1;
}

void StringPool::operator*=(const char* str)
{
	if (!isValidString(str))
		return;
	if (stringCount == stringCapacity)
		resize(stringCapacity * 2);

	int firstFreeIndex = stringCount++;

	stringRecords[firstFreeIndex].str = new char[std::strlen(str) + 1];
	std::strcpy(stringRecords[firstFreeIndex].str, str);
	stringRecords[firstFreeIndex].refCount = 0;
	sort();
}

void StringPool::operator/=(const char* str)
{
	unsigned index = findAllocatedString(str);
	std::swap(stringRecords[index], stringRecords[stringCount - 1]);

	delete[] stringRecords[stringCount - 1].str;
	stringRecords[stringCount - 1].str = nullptr;
	stringRecords[stringCount--].refCount = 0;
	sort();
}

std::ostream& operator<<(std::ostream& os, const StringPool& pool)
{
	for (int i = 0;i < pool.stringCount;i++)
	{
		os << pool.stringRecords[i].str << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, StringPool& pool)
{
	char buff[1024];
	is >> buff;
	pool *= buff;

	return is;
}

StringPool operator+(const StringPool& lhs, const StringPool& rhs)
{
	StringPool pool=lhs;
	return pool += rhs;
}
StringPool operator-(const StringPool& lhs, const StringPool& rhs)
{
	StringPool pool = lhs;
	return pool -= rhs;
}

int main(){}