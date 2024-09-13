#pragma once
#include <iostream>
class Bitset
{
public:
	Bitset();
	Bitset(unsigned n);
	Bitset(const Bitset& other);
	Bitset(Bitset&& other);
	
	Bitset& operator=(const Bitset& other);
	Bitset& operator=(Bitset&& other);


	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print() const;
	void printMemory() const;
	friend Bitset UnionOfSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset IntersectionOfSets(const Bitset& lhs, const Bitset& rhs);

private:
	uint8_t* buckets;
	size_t numberOfBuckets;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const Bitset& other);
	void moveFrom(Bitset&& other);

	void resize(unsigned num);
	unsigned getBucketIndex(unsigned num) const;
};