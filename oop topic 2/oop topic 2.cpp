#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>


    //filesize
//void fileSize()
//{
//	std::ifstream file("file2.txt");
//
//	unsigned size = 0;
//	while (true)
//	{
//		file.get();
//		if (file.eof())
//			break;
//		size++;
//
//	}
//
//	std::cout << size;
//}

     //csv parser

namespace GlobalConstants {

	constexpr int FIELD_MAX_SIZE = 30;
	constexpr int MAX_FIELDS_ROW = 10;
	constexpr int ROWS_MAX_SIZE = 300;
	constexpr int BUFFER_SIZE = 1024;
	constexpr char SEP = ',';
}

typedef char Field[GlobalConstants::FIELD_MAX_SIZE];//field e masiv ot charove
typedef Field Row[GlobalConstants::MAX_FIELDS_ROW];//row e masiv of fields

struct CsvTable {
	Row rows[GlobalConstants::ROWS_MAX_SIZE];
	size_t rowsCount = 0;
	size_t colsCount = 0;
};

size_t parseRow(const char* row, Row& toReturn)
{
	std::stringstream ss(row);

	size_t currentColsCount = 0;

	while (!ss.eof())
	{
		ss.getline(toReturn[currentColsCount++], GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
	}

	return currentColsCount;
}

CsvTable parseFromFile(std::ifstream& ifs)
{
	CsvTable result;

	char rowStr[GlobalConstants::BUFFER_SIZE];

	while (!ifs.eof())
	{
		ifs.getline(rowStr, GlobalConstants::BUFFER_SIZE,'\n');
		result.colsCount = parseRow(rowStr, result.rows[result.rowsCount++]);
	}

	return result;
}

CsvTable parseFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return {};
	}

	return parseFromFile(ifs);
}

void printTable(const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		for (int j = 0; j < table.colsCount; j++)
		{
			std::cout << table.rows[i][j] << "          ";
		}
		std::cout << std::endl;
	}
}

int getColumnIndex(CsvTable csvTable, const char* columnName)
{
	assert(csvTable.rowsCount >= 1);
	if (!columnName)
		return -1;

	for (int i = 0; i < csvTable.colsCount; i++)
	{
		if (strcmp(csvTable.rows[0][i], columnName) == 0)
			return i;
	}
	return -1;
}

bool modify(CsvTable& table, const char* columnName, const char* newValues, char sep)
{
	int columnIndex = getColumnIndex(table, columnName);
	if (columnIndex < 0)
		return false;

	std::stringstream ss(newValues);
	int rowIndex = 1;
	
	while (!ss.eof())
	{
		if (rowIndex >= table.rowsCount)
			break;

		ss.getline(table.rows[rowIndex++][columnIndex], GlobalConstants::FIELD_MAX_SIZE, sep);
	}
	return true;
}

void saveRowToFile(std::ofstream& ofs, const Row& row, size_t colsCount) 
{
	for (int i = 0;i < colsCount;i++)
	{
		ofs << row[i];
		if (i != colsCount - 1)
			ofs << GlobalConstants::SEP;
	}
}

void saveToFile(std::ofstream& ofs, const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		saveRowToFile(ofs, table.rows[i], table.colsCount);
		if (i != table.rowsCount - 1)
		{
			ofs << std::endl;
		}
	}
}

void saveToFile(const char* fileName, const CsvTable& table)
{
	if (!fileName)
		return;
	std::ofstream ofs(fileName);

	if (!ofs.is_open())
		return;

	saveToFile(ofs, table);
	ofs.close();
}

int main()
{
	CsvTable myFile = parseFromFile("students1.csv");

	printTable(myFile);

	modify(myFile, "Fakulteten nomer", "123|123|123|123|123|123|123|123|123|123|123|123|123|123|123", '|');

	saveToFile("students_new.csv", myFile);
}

