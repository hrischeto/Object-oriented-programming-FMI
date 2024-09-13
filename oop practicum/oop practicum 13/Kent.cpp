#include "Kent.h"
bool Kent::fightWith(const Creature* other) const
{
	return !other->figthWithKentaur();
}

bool Kent::figthWithMinotaur() const
{
	return 1;
}
bool Kent::figthWithKentaur() const
{
	return 1;
}
bool Kent::figthWithSfinx() const
{
	return 0;
}