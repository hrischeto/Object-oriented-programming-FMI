#pragma once

class Creature {
public: 
	virtual ~Creature()=default;

	virtual bool fightWith(const Creature* other) const = 0;

	virtual bool figthWithMinotaur() const = 0;
	virtual bool figthWithKentaur() const = 0;
	virtual bool figthWithSfinx() const = 0;
};