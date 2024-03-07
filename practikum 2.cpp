
#include <iostream>
#include <fstream>

constexpr size_t MAX_SIZE = 1024;
constexpr size_t MAX_NUMBERS_IN_ARRAY = 64;
constexpr size_t MAX_PAIRS = 25;
constexpr size_t MAX_NAME_LENGHT = 63;
constexpr size_t MAX_CITIES = 20;


/*zad1*/

void sumAndDifference(std::ofstream& ofs, int a, int b) {
    ofs << a + b << " " << a - b;

}

void findAddends(std::ifstream& ifs) {
    int sum, difference;
    ifs >> sum >> difference;
    
    int first = (sum + difference) / 2;
    int second = sum - first;

    std::cout << first << " " << second << std::endl;
}

int firstExercise() {

    std::ofstream ofs("result.txt");

    if (!ofs.is_open()) {
        std::cerr << "Error while opening file for writing." << std::endl;
        return -1;
    }

    std::ifstream ifs("result.txt");

    if (!ifs.is_open()) {
        std::cerr << "Error while opening file for reading." << std::endl;
        return -1;
    }

    sumAndDifference(ofs, 7, 6);
    ofs.clear();
    ofs.close();

    findAddends(ifs);
    ifs.clear();
    ifs.close();

    std::ofstream ofs("result.txt");

    if (!ofs.is_open()) {
        std::cerr << "Error while opening file for writing." << std::endl;
        return -1;
    }

    std::ifstream ifs("result.txt");

    if (!ifs.is_open()) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    sumAndDifference(ofs, 7, 6);
    ofs.clear();
    ofs.close();

    findAddends(ifs);
    ifs.clear();
    ifs.close();
}

/*zad2*/
int countOccurences(int* arr, int element, size_t arrLenght)
{
    if (!arr)
        return -1;

    int count = 0;

    for (int i = 0; i < arrLenght;i++)
    {
        if (arr[i] == element)
            count++;
    }
    return count;
}

int mostCommonNumber(size_t numbersCount, int* arr)
{
    if (!arr)
        return -1;

    int mostOccurences = 0;
    int mostCommonElement = arr[0];
    int currentCount = 0;

    for (int i = 0;i < numbersCount;i++)
    {
        currentCount=countOccurences(arr, arr[i], numbersCount);

        if (currentCount > mostOccurences) {
            mostOccurences = currentCount;
            mostCommonElement = arr[i];
        }

    }


    return mostCommonElement;
}

void exTwo() {
    std::ifstream file("result.txt");
    if (!file.is_open()) {
        std::cerr << "Error while opening file for reading" << std::endl;
        return;
    }

    int buffer[MAX_NUMBERS_IN_ARRAY + 1];

    unsigned numbersCount = 0;

    file >> numbersCount;

    for (int i = 0;i < numbersCount;i++)
    {
        file >> buffer[i];
    }

   std::cout<< mostCommonNumber(numbersCount, buffer);

}

/*zad3*/

void selfPrinting()
{
	std::ifstream program("practikum 2.cpp");

	if (!program.is_open())
	{
		std::cout << "Error" << std::endl;
		return;
	}

	char buffer[1024];
	while (!program.eof())
	{
		program.getline(buffer, 1024);
		std::cout << buffer << std::endl;
	}
}

/*zad4*/

bool compareRows(const char* buff1, const char* buff2)
{
	if (!(buff1 && buff2))
		return 0;

	int characters = 0;
	while (*buff1 || *buff2)
	{
		if (*buff1 != *buff2)
		{
			buff1 -= characters;
			buff2 -= characters;
			return 1;
		}
		characters++;
		buff1++;
		buff2++;
	}

	return 0;
}
void compareFiles()
{
	std::ifstream file1("file1.txt");
	std::ifstream file2("file2.txt");

	if (!file1.is_open())                               
	{
		std::cout << "error1" << std::endl;
		return;
	}

	if (!file2.is_open())
	{
		std::cout << "error2" << std::endl;
		return;
	}

	char buffer1[MAX_SIZE];
	char buffer2[MAX_SIZE];

	while (!file1.eof() || !file2.eof())
	{
		if (file1.eof())
		{
			file2.getline(buffer2, MAX_SIZE);
			std::cout << "Row in file 2: " << buffer2 << std::endl;
			return;
		}
		else if (file2.eof())
		{
			file1.getline(buffer1, MAX_SIZE);
			std::cout <<"Row in file 1: " << buffer1 << std::endl;
			return;
		}
		else
		{
			file1.getline(buffer1, MAX_SIZE);
			file2.getline(buffer2, MAX_SIZE);
			
			if (compareRows(buffer1, buffer2))
			{
				std::cout << "Row in file 1: " << buffer1 << std::endl;
				std::cout << "Row in file 2: " << buffer2 << std::endl;
				return;
			}
		}
	}

	std::cout <<"The files are identical." << std::endl;
}

/*zad5*/

struct Pair {
	double a;
	double b;
};

struct Relation {
	Pair PairsInRelation[MAX_PAIRS];
	size_t pairsCount=0;
};

Pair readRelation(std::ifstream& relations)
{
	Pair pairInRelation;

	relations >> pairInRelation.a;
	relations >> pairInRelation.b;

	return pairInRelation;
}

void addPairToRelation(const Pair& pairInRelation, Relation& rel)
{
	rel.PairsInRelation[rel.pairsCount] = pairInRelation;
	rel.pairsCount++;
}

void writeInFile(std::ofstream& file, const Relation& rel)
{
	Pair currentPair;
	for (int i = 0; i < rel.pairsCount;i++)
	{
		currentPair = rel.PairsInRelation[i];
		file << '(' << currentPair.a << ", " << currentPair.b << ')' << std::endl;
	}
}
void exerciseFive()
{
	std::ifstream relations("relations.txt");
	std::ofstream file("relation.txt");
	if (!relations.is_open())
	{
		std::cout << "Error while opening file for reading." << std::endl;
		return;
	}
	if (!file.is_open())
	{
		std::cout << "Error while opening file for writing." << std::endl;
		return;
	}

	Relation myRel;
	while (!relations.eof())
	{
		addPairToRelation(readRelation(relations), myRel);
	}

	relations.clear();
	relations.close();

	writeInFile(file, myRel);
}

/*zad6*/

struct City {
	char name[MAX_NAME_LENGHT];
	unsigned citizens = 0;
};

struct District {
	City district[MAX_CITIES];
	unsigned citiesCount = 0;
};

void writeDistrictInFile(std::ofstream& file, const District& myDistrict)
{
	for (unsigned i = 0;i < myDistrict.citiesCount;i++)
	{
		file << myDistrict.district[i].name << " " << myDistrict.district[i].citizens<<std::endl;
	}
}

void addCityToDistrict(const City& newCity, District& myDistrict)
{
	myDistrict.district[myDistrict.citiesCount++] = newCity;
}

District getDistFromFile(std::ifstream& unsorted)
{
	District newDistrict;

	char nameBuffer[MAX_NAME_LENGHT];
	while (true)
	{
		unsorted.getline(nameBuffer, MAX_NAME_LENGHT, ' ');
		if (unsorted.eof())
			break;

		strcpy_s(newDistrict.district[newDistrict.citiesCount].name, nameBuffer);
		unsorted >> newDistrict.district[newDistrict.citiesCount++].citizens;
	}
	
	return newDistrict;
}

void sortDistrict(std::ifstream& unsorted)
{
	District dist = getDistFromFile(unsorted);

	for (size_t i = 0;i < dist.citiesCount-1;i++)
	{
		int minElementIndex = i;
		for (size_t j = i+1;j < dist.citiesCount;j++)
		{
			if(dist.district[j].citizens < dist.district[minElementIndex].citizens)
				minElementIndex=j;
		}

		if (minElementIndex != i)
			std::swap(dist.district[minElementIndex], dist.district[i]);
	}

	std::ofstream sorted("sorted.txt");
	if (!sorted.is_open())
	{
		std::cout << "Error writing" << std::endl;
		return;
	}

	writeDistrictInFile(sorted, dist);
	
}

void exerciseSix()
{
	std::ofstream file("unsorted.txt");
	if (!file.is_open())
	{
		std::cout << "Error writing" << std::endl;
		return;
	}

	District myDistrict;
	City newCity;

	for (int i = 0;i < 3;i++)
	{
		std::cin >> newCity.name;
		std::cin >> newCity.citizens;

		addCityToDistrict(newCity, myDistrict);
	}

	writeDistrictInFile(file, myDistrict);

	file.clear();
	file.close();

	std::ifstream unsorted("unsorted.txt");
	if (!unsorted.is_open())
	{
		std::cout << "Error reading" << std::endl;
		return;
	}

	sortDistrict(unsorted);
}
int main()
{
	exerciseSix();
}