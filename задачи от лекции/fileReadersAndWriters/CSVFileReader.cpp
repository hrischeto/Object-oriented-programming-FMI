#include "CSVFileReader.h"

int CSVFileReader::getCharCount(std::ifstream& ifs, char ch)
{
	size_t currPos = ifs.tellg();

	if (!ifs.is_open()) {
		return -1;
	}

	int count = 0;
	while (true) {
		char current = ifs.get();

		if (ifs.eof()) {
			break;
		}

		if (current == ch) {
			count++;
		}
	}

	ifs.clear();
	ifs.seekg(currPos);
	return count;
}

CSVFileReader::CSVFileReader(const MyString& filePath) :FileReader(filePath) {}

int* CSVFileReader::read(size_t& size) const
{
	std::ifstream ifs(filePath.c_str());
	if (!ifs.is_open())
		throw std::exception("");

	size = getCharCount(ifs, ',')+1;

	int* arr = new int[size];

	for (int i = 0;i < size;i++)
	{
		ifs >> arr[i];
		ifs.ignore();
	}

	ifs.close();
	return arr;
}