#include "Multiset.h"

void Multiset::copyFrom(const Multiset& other)
{
	N = other.N;
	numberOfBuckets = other.numberOfBuckets;
	buckets = new uint8_t[numberOfBuckets];

	for (int i = 0;i < numberOfBuckets;i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void Multiset::free()
{
	delete[] buckets;
}

unsigned Multiset::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

Multiset::Multiset(int N)
{
	numberOfBuckets = N / elementsInBucket + 1;
	this->N = N;
	buckets = new uint8_t[numberOfBuckets]{ 0 };
}

Multiset::Multiset(const Multiset& other)
{
	copyFrom(other);
}

Multiset& Multiset::operator=(const Multiset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Multiset::~Multiset()
{
	free();
}

void Multiset::add(unsigned num)
{
	if (num > N)
		return;

	int times = containsTimes(num);
	if (times == maxTimesIncluded)
		return;

	times++;
	unsigned toShift =( elementsInBucket - (num % elementsInBucket+1))*2;
	uint8_t mask = times << toShift;
	unsigned bucketIndex = getBucketIndex(num);
	uint8_t maskClear = ~(3 << toShift);
	buckets[bucketIndex] &= maskClear;
	buckets[bucketIndex] |= mask;
}

void Multiset::remove(unsigned num)
{
	if (num > N)
		return;

	int times = containsTimes(num);
	if (times == 0)
		return;

	times--;
	unsigned toShift = (elementsInBucket - (num % elementsInBucket+1)) * 2;
	uint8_t mask = times << toShift;
	unsigned bucketIndex = getBucketIndex(num);
	uint8_t maskClear = ~(3 << toShift);
	buckets[bucketIndex] &= maskClear;
	buckets[bucketIndex] |= mask;
}

unsigned Multiset::containsTimes(unsigned num) const
{

	if (num > N)
		return 0;

	unsigned toShift =( elementsInBucket - (num % elementsInBucket+1))* 2;
	uint8_t mask = 3 << toShift;
	unsigned bucketIndex = getBucketIndex(num);
	mask &= buckets[bucketIndex];
	mask >>= toShift;
	return mask;
}

void Multiset::printMemory() const
{
	for (int i = 0;i <= N;i++)
	{
		unsigned times = containsTimes(i);

		switch (times)
		{
		case 0:
			std::cout << "00";
			break;
		case 1:
			std::cout << "01";
			break;
		case 2:
			std::cout << "10";
			break;
		case 3:
			std::cout << "11";
			break;
		}

		if ((i + 1) % elementsInBucket == 0)
			std::cout << "|";
		else
			std::cout << " ";

	}
}

void Multiset::print() const
{
	for (int i = 0;i <= N;i++)
	{
		unsigned times = containsTimes(i);
		if (times > 0)
			std::cout << i << "x" << times << " ";
	}
	std::cout << std::endl;
}

Multiset unionOfSets(const Multiset& lhs, const Multiset& rhs)
{
	const Multiset& biggerSet = (lhs.N > rhs.N ? lhs : rhs);
	Multiset result = biggerSet;
	const Multiset& smallerSet = (lhs.N < rhs.N ? lhs : rhs);

	for (int i = 0;i < smallerSet.numberOfBuckets;i++)
	{
		result.buckets[i] |= smallerSet.buckets[i];
	}

	return result;
}

Multiset intersectionOfSet(const Multiset& lhs, const Multiset& rhs)
{
	const Multiset& biggerSet = (lhs.N > rhs.N ? lhs : rhs);
	const Multiset& smallerSet = (lhs.N < rhs.N ? lhs : rhs);

	Multiset result = smallerSet;

	for (int i = 0;i < smallerSet.numberOfBuckets;i++)
	{
		result.buckets[i] &= biggerSet.buckets[i];
	}

	return result;
}