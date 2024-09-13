#pragma once

class StringPool
{
public:
	StringPool();
	StringPool(const StringPool&) = delete;
	StringPool& operator=(const StringPool&) = delete;
	~StringPool();

	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);

private:
	unsigned allocatedNewString(const char* str);
	void resize(size_t newCap);
	int findAllocatedString(const char* str) const;
	void removeRecord(unsigned index);

	struct StringRecord
	{
		char* str=nullptr;
		unsigned refCount;
	};

	StringRecord* stringRecords=nullptr;
	size_t stringCount = 0;
	size_t stringCapacity = 0;
};