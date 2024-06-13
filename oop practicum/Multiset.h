#pragma once

const unsigned numbersInBucket = 4;

class Multiset
{
private:
	uint8_t* Bitset;
	int N = 0;
	size_t buckets = N / numbersInBucket+1;

	void copyFrom(const Multiset&) {};
	void free() {};

public:

	Multiset(int N) {};
	Multiset(const Multiset& other) {};
	Multiset& operator=(const Multiset& other) {};
	~Multiset() {};
};