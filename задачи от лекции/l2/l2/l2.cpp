#include <iostream>
#include <fstream>
//newlines count
//const char NEW_LINE_SYMBOL = '\n';
//
//int  symbolsCount(std::ifstream& ifs, char ch)
//	{
//
//	if (!ifs.is_open())
//		return -1;
//
//	char symbol;
//	unsigned counter = 0;
//	while (true)
//	{
//		symbol = ifs.get();
//		if (ifs.eof())
//			return counter;
//
//		if (symbol == ch)
//			counter++;
//	}
//
//	return 0;
//	}
//
//int  newLinesCount(const char* filepath)
//{
//	std::ifstream ifs("filepath");
//	if (!ifs.is_open())
//		return -1;
//
//		return symbolsCount(ifs, NEW_LINE_SYMBOL)+1;
//}
//selfPrinting
void selfPrinting() {

	std::ifstream ifs("l2.cpp");

	if (!ifs.is_open()) {
		std::cout << "couldnt open";
		return;
	}
	while (!ifs.eof())
	{
		char buffer[1024];
		ifs.getline(buffer, 1024);

		std::cout << buffer << std::endl;
	}
}

//getSize

size_t getFileSize(const char* filepath)
{
	std::ofstream ofs(filepath);

	if (!ofs.is_open())
		return -1;

	size_t currPosition = ofs.tellp();

	ofs.seekp(0, std::ios::end);

	size_t size = ofs.tellp();

	ofs.seekp(currPosition);

	return size;
}

//merge_sorted_text_files




int main() {
	
	selfPrinting();

	
}