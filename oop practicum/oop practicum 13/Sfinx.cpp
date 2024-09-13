#include "Sfinx.h"
bool Sfinx::fightWith(const Creature* other) const
{
	return !(other->figthWithSfinx());
}

bool Sfinx::figthWithMinotaur() const
{
	return 0;
}
bool Sfinx::figthWithKentaur() const
{
	return 1;
}
bool Sfinx::figthWithSfinx() const
{
	return 1;
}