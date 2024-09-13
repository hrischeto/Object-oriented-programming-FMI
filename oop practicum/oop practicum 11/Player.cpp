#include "Player.h"
unsigned Player::playersCount = 0;

Player::Player()
{
	setId();
	stars = Star::One;
	points = 0;
}

int Player::getId() const
{
	return id;
}
uint32_t Player::getPoints() const
{
	return points;
}
Player::Star Player::getStars() const
{
	return stars;
}

void Player::setPoints(int newPoints)
{
	points = newPoints;
}
bool Player::levelUp()
{
	if (stars == Star::five)
		return false;
	int next = (int)stars<<1;

	if (points >= next)
	{
		stars = (Star)next;
		return true;
	}
	else
		return false;
}

void Player::setId()
{
	playersCount++;
	id = playersCount;
	std::cout << "id:" << id;
}
