#pragma once
#include "Set.h"

class SetOperation :public Set
{
public:
	SetOperation(const Set** sets, size_t size);
	SetOperation(Set**&& sets, size_t size);

	SetOperation(const SetOperation& other);
	SetOperation(SetOperation&& other);

	SetOperation* operator=(const SetOperation& other);
	SetOperation* operator=(SetOperation&& other);

	~SetOperation();

protected:
	void copyFrom(const SetOperation& other);
	void moveFrom(SetOperation&& other);
	void free();

	Set** data = nullptr;
	size_t size = 0;
};