#include "Min.h"

bool Min::fightWith(const Creature* other) const
{
	return !other->figthWithMinotaur();
}

bool Min::figthWithMinotaur() const
{
	return 1;
}
bool Min::figthWithKentaur() const
{
	return 0;
}
bool Min::figthWithSfinx() const
{
	return 1;
}