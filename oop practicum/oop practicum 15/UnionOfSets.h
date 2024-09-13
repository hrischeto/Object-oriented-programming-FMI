#pragma once
#include "SetOperation.h"

class UnionOfSets : public SetOperation
{
	UnionOfSets(const Set** sets, size_t size);
	UnionOfSets(Set**&& sets, size_t size);

	bool accepts(unsigned num) const;
	Set* clone() const override;

};

