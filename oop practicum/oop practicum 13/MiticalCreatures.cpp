#include "Creature.h"
#include "Kent.h"
#include "Sfinx.h"
#include "Min.h"

#include <iostream>

Creature* fact()
{
	int a;
	std::cin >> a;

	switch (a)
	{
	case 1:
		return new Min;
	case 2:
		return new Kent;
	case 3:
		return new Sfinx;
	}
}

int figth(int index, Creature** arr, int size)
{
	int count = 0;
	for (int i = 0;i < size;i++)
	{
		if (i == index)
			continue;

		count += arr[index]->fightWith(arr[i]);
	}

	return count;
}

int main()
{
	Creature** arr = new Creature * [5] {nullptr};

	for (int i = 0;i < 5;i++)
	{
		arr[i] = fact();
	}

	std::cout << figth(0, arr, 5);
}