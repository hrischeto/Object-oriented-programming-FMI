#pragma once
#include "Collection.h"
#include "PureNumbersCollection.h"

enum CollectionType {
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

class Set : public Collection
{
	PureNumbersCollection* collection;

public:
	Set(CollectionType);

	Set(const Set&) = delete;
	Set& operator=(const Set&) = delete;

	void add(int el) override;
	void remove(int el) override;
	int count(int el) const override;
	bool contains(int el) const override;

	~Set();
};

