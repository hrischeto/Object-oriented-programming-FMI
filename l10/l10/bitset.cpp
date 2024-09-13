#include "bitset.h"

Bitset::Bitset()
{
	buckets = new uint8_t[1]{ 0 };
	numberOfBuckets = 1;
	N = 7;
}

Bitset::Bitset(unsigned n)
{
	N = n;
	numberOfBuckets = N / elementsInBucket + 1;
	buckets = new uint8_t[numberOfBuckets]{ 0 };
}

Bitset::Bitset(const Bitset& other)
{
	copyFrom(other);
}
Bitset::Bitset(Bitset&& other)
{
	moveFrom(std::move(other));
}

Bitset& Bitset::operator=(const Bitset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Bitset& Bitset::operator=(Bitset&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

unsigned Bitset::getN() const
{
	return N;
}

void Bitset::add(unsigned num)
{
	if (num > N)
		resize(num);

	unsigned bucketIndex = getBucketIndex(num);
	unsigned toShift = elementsInBucket - (num % elementsInBucket) - 1;

	uint8_t mask = 1 << toShift;
	buckets[bucketIndex] |= mask;

}

void Bitset::remove(unsigned num)
{
	if (num > N)
		return;

	unsigned bucketIndex = getBucketIndex(num);
	unsigned toShift = elementsInBucket - (num % elementsInBucket) - 1;

	uint8_t mask = ~(1 << toShift);
	buckets[bucketIndex] &= mask;

}

bool Bitset::contains(unsigned num) const
{
	if (num > N)
		return 0;

	unsigned bucketIndex = getBucketIndex(num);
	unsigned toShift = elementsInBucket-(num % elementsInBucket)-1;

	uint8_t mask = 1 << toShift;
	return buckets[bucketIndex] & mask;
}

void Bitset::print() const
{
	std::cout << "{";
	for (int i = 0;i <= N;i++) {
		if (contains(i))
			std::cout << i << " ";
	}
	std::cout << "}" << std::endl;
}

void Bitset::printMemory() const
{
	for (int i = 0;i <= N;i++)
	{
		if (contains(i))
			std::cout << 1;
		else
			std::cout << 0;
		if ((i + 1) % elementsInBucket == 0)
			std::cout << " ";
	}

	std::cout << std::endl;
}

void Bitset::free()
{
	delete[] buckets;
	N = 0;
	numberOfBuckets = 0;
}

void Bitset::copyFrom(const Bitset& other)
{
	N = other.N;
	numberOfBuckets = other.numberOfBuckets;
	buckets = new uint8_t[numberOfBuckets]{ 0 };

	for (int i = 0;i < numberOfBuckets;i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void Bitset::moveFrom(Bitset&& other)
{
	N = other.N;
	numberOfBuckets = other.numberOfBuckets;
	buckets = other.buckets;

	other.buckets = nullptr;
	other.N = 0;
	other.numberOfBuckets = 0;
}

void Bitset::resize(unsigned num)
{
	if (num < elementsInBucket * numberOfBuckets - 1) {
		N = numberOfBuckets * elementsInBucket - 1;
		return;
	}

	size_t newSize = getBucketIndex(num)+1;

	uint8_t* newData = new uint8_t[newSize]{ 0 };

	for (int i = 0;i < numberOfBuckets;i++)
	{
		newData[i] = buckets[i];
	}

	delete[] buckets;
	buckets = newData;

	numberOfBuckets = newSize;
	N = numberOfBuckets * elementsInBucket - 1;
}

unsigned Bitset::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;

}

Bitset UnionOfSets(const Bitset& lhs, const Bitset& rhs)
{
	Bitset result(std::max(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.numberOfBuckets, rhs.numberOfBuckets);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] | rhs.buckets[i];

	const Bitset& biggerN = lhs.numberOfBuckets > rhs.numberOfBuckets ? lhs : rhs; //no copy here

	for (int i = minBucketsCount; i < biggerN.numberOfBuckets; i++)
		result.buckets[i] = biggerN.buckets[i];
	return result;
}

Bitset IntersectionOfSets(const Bitset& lhs, const Bitset& rhs)
{
	Bitset result(std::min(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.numberOfBuckets, rhs.numberOfBuckets);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	return result;
}

void Bitset::emptySet()
{
	for (int i = 0;i < numberOfBuckets;i++)
	{
		buckets[i] &= 0;
	}
}

