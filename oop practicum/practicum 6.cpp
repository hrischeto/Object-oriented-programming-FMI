#pragma once
#include <iostream>
#include "Multiset.h"

Multiset::Multiset(int N)
{
	this->N = N;
	buckets= N / numbersInBucket + 1;//
	Bitset = new uint8_t[buckets];
}

void Multiset::copyFrom(const Multiset& other)
{
	this->N = other.N;
	this->buckets = other.buckets;
	for (int i = 0;i < buckets;i++)
	{
		this->Bitset[i] = other.Bitset[i];
	}
}

void Multiset::free()
{
	this->N = 0;
	this->buckets = 0;
	delete[] Bitset;
}

Multiset::Multiset(const Multiset& other)
{
	copyFrom(other);
}

Multiset