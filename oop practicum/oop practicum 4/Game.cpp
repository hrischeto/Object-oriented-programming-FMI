#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

const size_t MAX_TITLE_LEN = 64;
class Game
{
public:
	Game() = default;
	Game(const char* title, double price, bool isAvailable) :price(price), isAvailable(isAvailable)
	{
		setTitle(title);
	}

	void setTitle(const char* title)
	{
		size_t len = std::strlen(title);
		if (len <= MAX_TITLE_LEN)
			std::strcpy(this->title, title);
		else
			std::strcpy(this->title, "unknown");
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	void setAvailability(bool isAv)
	{
		isAvailable = isAv;
	}

	const char* getTitle() const
	{
		return title;
	}

	double getPrice() const
	{
		return price;
	}

	bool getAvailability() const
	{
		return isAvailable;
	}

	bool isFree() const
	{
		return !getPrice();
	}

	void print() const
	{
		std::cout << "Title:" << title << " |Price:" << price << "lv |In stock:" << (isAvailable ? "Yes" : "No") << std::endl;
	}

	void readGame(std::ifstream& file)
	{
		file.getline(title, MAX_TITLE_LEN, '\n');
		file >> price >> isAvailable;
		file.ignore();
	}

	void serialize(std::ofstream& ofs) const
	{
		ofs << title << '\n' << price << '\n' << isAvailable << '\n';
	}

private:
	char title[MAX_TITLE_LEN]{};
	double price = 0;
	bool isAvailable = 0;
};

class GamePlatform
{
public:
	GamePlatform()
	{
		games = nullptr;
		size = 0;
	}
	~GamePlatform()
	{
		delete[] games;
	}

	GamePlatform(const char* filePath)
	{
		std::ifstream file(filePath);
		if (!file.is_open())
		{
			games = nullptr;
			size = 0;
			return;
		}

		file >> size;
		capacity = size * 2;
		games = new Game[capacity];

		for (int i = 0;i < size;i++)
		{
			games[i].readGame(file);
		}
		file.close();
	}

	GamePlatform(Game* games, size_t size)
	{
		this->games = games;
		capacity = size * 2;
		this->size = size;
	}

	void serialize(const char* filePath) const 
	{
		std::ofstream ofs(filePath, std::ios::out);

		if (!ofs.is_open())
			return;

		ofs << size;
		for (int i = 0;i < size;i++)
		{
			games[i].serialize(ofs);
		}
	}

	void printByIndex(int ind) const
	{
		if (ind >= size)
			return;

		games[ind].print();
	}

	void printPlatform() const
	{
		for (int i = 0;i < size;i++)
		{
			games[i].print();
		}
	}

	void getCheapest() const
	{
		std::cout << "Cheapest game:\n";

		double least = INT_MAX;
		int index = 0;

		for (int i = 0;i < size;i++)
		{
			double current = games[i].getPrice();
			if (current < least) {
				least = current;
				index = i;
			}
		}

		games[index].print();
	}

	void getMostExpensive() const
	{
		std::cout << "Most expensive game:\n";
		double most = 0;
		int index = 0;

		for (int i = 0;i < size;i++)
		{
			double current = games[i].getPrice();
			if (current > most) {
				most = current;
				index = i;
			}
		}

		games[index].print();
	}

	void add(Game& game)
	{
		if (size < capacity)
		{
			games[size] = game;
			size++;
		}
	}

	void remove()
	{
		size--;
	}

	void removeByIndex(int ind)
	{
		if (ind < size)
		{
			for (int i = ind;i < size - 1;i++)
			{
				games[i] = games[i + 1];
			}

			size--;
		}
	}

	void getFreeGames() const
	{
		std::cout << "Free games: \n";
		for (int i = 0;i < size;i++)
		{
			if (games[i].getPrice() == 0)
				games[i].print();
		}
	}


private:
	Game* games = nullptr;
	size_t size = 0;
	size_t capacity = 0;
};
int main()
{/*
	Game cs("Call of Duty", 8.50, 1);
	Game two("Minecraft", 5, 1);
	Game three("Lady Popular", 3, 0);*/

	//Game* arr = new Game[3];
	//arr[0] = cs;
	//arr[1] = two;
	//arr[2] = three;
	GamePlatform pl("platform.txt");
	Game four("Subway Surfers", 0, 1);
	pl.add(four);
	Game five("Pou", 0, 0);
	pl.add(five);
	pl.getFreeGames();
	pl.getMostExpensive();
	pl.printByIndex(2);
	pl.getCheapest();
	pl.serialize("platform.txt");
	pl.printPlatform();
}