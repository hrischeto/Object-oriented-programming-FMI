#pragma once
#include "SetOperation.h"
class IntersectionOfSets : public SetOperation
{
	IntersectionOfSets(const Set** sets, size_t size);
	IntersectionOfSets(Set**&& sets, size_t size);

	bool accepts(unsigned num) const override;
	Set* clone() const override;
};

