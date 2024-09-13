#pragma once
#include <iostream>

class Multiset
{
private:
	uint8_t* buckets;
	size_t numberOfBuckets = 0;
	unsigned N = 0;
	const unsigned bitsByElement = 2;
	const unsigned elementsInBucket = sizeof(uint8_t)*(8/bitsByElement);
	const unsigned maxTimesIncluded = 3;
	void copyFrom(const Multiset& other);
	void free();
	unsigned getBucketIndex(unsigned num) const;
public:
	Multiset(int N);
	Multiset(const Multiset& other);
	Multiset& operator=(const Multiset& other);
	~Multiset();

	void add(unsigned num);
	void remove(unsigned num);
	unsigned containsTimes(unsigned num) const;

	void print() const;
	void printMemory() const;

	friend Multiset unionOfSets(const Multiset& lhs, const Multiset& rhs);
	friend Multiset intersectionOfSet(const Multiset& lhs, const Multiset& rhs);
};

