#pragma once
#include "Creature.h"
class Kent :
    public Creature
{
public:

	bool fightWith(const Creature* other) const override;

	bool figthWithMinotaur() const override;
	bool figthWithKentaur() const override;
	bool figthWithSfinx() const override;
};

