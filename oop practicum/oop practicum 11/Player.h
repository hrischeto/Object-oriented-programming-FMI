#pragma once
#include <iostream>

class Player
{
public:
	enum class Star {
		One = 1,
		two = 256,
		three = 512,
		four = 1024,
		five = 2044
	};
	
	int getId() const;
	uint32_t getPoints() const;
	Star getStars() const;

	void setPoints(int newPoints);
	virtual bool levelUp();
	Player();
	virtual ~Player() = default;
protected:
	int id = 0;
	uint16_t points;
	Star stars = Star::One;
	
private:
	static unsigned playersCount;
	void setId();
};