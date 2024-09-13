#include <iostream>
#include <fstream>
#include <iomanip>
#pragma warning(disable:4996)

struct HexViewer {
	char* filePath;
	unsigned char* data;
	size_t dataSize;
};

bool isValidSymbol(char ch)
{
		return ch >= 'a' && ch <= 'z' ||
			ch >= 'A' && ch <= 'Z' ||
			ch >= '0' && ch <= '9';
}

size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();

	file.seekg(0, std::ios::end);
	size_t size = file.tellg();

	file.seekg(currentPos);

	return size;
}

HexViewer init(const char* filePath)
{
	std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

	HexViewer myFile;

	if (!ifs.is_open())
	{
		myFile.data = nullptr;
		myFile.dataSize = 0;
		myFile.filePath = nullptr;
		return myFile;
	}

	myFile.dataSize = getFileSize(ifs);
	myFile.data = new unsigned char[myFile.dataSize];

	ifs.read((char*)myFile.data, myFile.dataSize);

	ifs.close();
	
	size_t fileNameLen = std::strlen(filePath);
	myFile.filePath = new char[fileNameLen + 1];
	std::strcpy(myFile.filePath, filePath);

	return myFile;
}

void freeHexViewer(HexViewer& file)
{
	delete[] file.data;
	file.data = nullptr;
	file.dataSize = 0;
}

void print(const HexViewer& file)
{
	for (int i = 0;i < file.dataSize;i++)
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)file.data[i] << " ";
		
	std::cout << std::endl;

	for (int i = 0;i < file.dataSize;i++)
	{
		if (isValidSymbol(file.data[i]))
			std::cout << file.data[i] << " ";
		else
			std::cout << ".. ";
	}
	std::cout << std::endl;
}

int fromRandomToDecimal(char ch, unsigned k)
{
	int result = 0;
	unsigned mult = 1;

	while (ch)
	{
		result += ((ch% 10) * mult);
		mult *= k;
		ch /= 10;
	}
	return result;
}

void change(HexViewer& file, size_t index, char val)
{
	if (index >= file.dataSize) {
		return;
	}

	int dec = fromRandomToDecimal(val, 16);
	file.data[index] = dec;
}

void remove(HexViewer& file)
{
	file.dataSize--;
}

void add(HexViewer& file)
{
	unsigned char* newData = new unsigned char[file.dataSize+1];

	for (int i = 0;i < file.dataSize;i++)
		newData[i] = file.data[i];
	
	delete[] file.data;

	file.data = newData;
	newData[file.dataSize] = 0;

	file.dataSize++;

} 

void save(HexViewer& file)
{
	std::ofstream ofs(file.filePath, std::ios::ate | std::ios::binary);

	if (!ofs.is_open())
	{
		std::cout << "saving failed";
		return;
	}

	ofs.write((const char*)file.data, file.dataSize);

	ofs.close();
}

void saveAs(HexViewer& file, const char* filePath)
{
	std::ofstream ofs(filePath, std::ios::out | std::ios::binary);

	if (!ofs.is_open())
	{
		std::cout << "saving failed";
		return;
	}

	ofs.write((const char*)file.data, file.dataSize);

	ofs.close();
}
void f()
{
	HexViewer myFile = init("data.dat");
	print(myFile);

	change(myFile, 3, 78);
	std::cout << "data.dat contents\n";
	print(myFile);
	save(myFile);

	add(myFile);
	change(myFile, 4, 66);
	std::cout << "newdata.dat contents\n";
	print(myFile);
	saveAs(myFile, "newData.dat");

	freeHexViewer(myFile);
}

int main()
{
	int x = 25409;
	std::ofstream file("data.dat", std::ios::out | std::ios::binary);
	file.write((const char*)&x, sizeof(x));
	file.close();

	HexViewer myFile = init("data.dat");
	print(myFile);

	change(myFile, 1, 65);
	add(myFile);
	change(myFile, 4, 66);
	print(myFile);
	save(myFile);
}