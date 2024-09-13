#pragma once
#include <iostream>
class StringPool
{
public:
	StringPool();
	StringPool(const StringPool& other);
	StringPool& operator=(const StringPool& other);
	~StringPool();

	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);
	StringPool& operator+=(const StringPool& other);//Събиране на две колекции.
	StringPool& operator-=(const StringPool& other);//От думите на лявата колекция, се премахват тези, които участват в дясната.
	
	bool operator[](const char* str) const;//който приема дума и връща дали стрингът е в колекцията(очакваме логаритмично време).
	void operator*=(const char* str);
	void operator/=(const char* str);

	friend std::ostream& operator<<(std::ostream& os, const StringPool& pool);//Отпечатва всички думи в сортиран вид).
	friend std::istream& operator>>(std::istream& is, StringPool& pool);//Приема думa, която да се добави в речника).

private:
	unsigned allocatedNewString(const char* str);
	void resize(size_t newCap);
	int findAllocatedString(const char* str) const;
	void removeRecord(unsigned index);
	void sort();
	void copyFrom(const StringPool& other);
	void free();

	struct StringRecord
	{
		char* str=nullptr;
		unsigned refCount;
	};

	StringRecord* stringRecords=nullptr;
	size_t stringCount = 0;
	size_t stringCapacity = 0;
};

StringPool operator+(const StringPool& lhs, const StringPool& rhs);
StringPool operator-(const StringPool& lhs, const StringPool& rhs);

