//#include <iostream>
//#include <fstream>
//#pragma warning(disabled 4996)
//
//constexpr size_t MAX_CHARACTERS_IN_ARR = 1024;
//constexpr size_t MAX_CHARACTERS_IN_COMMAND = 7;
//constexpr char START_OF_COMMAND_PARAMETERS = '<';
//constexpr char END_OF_COMMAND_PARAMETERS = '>';
//constexpr size_t MAX_ROWS_COUNT = 100;
//constexpr size_t MAX_CELLS_COUNT = 15;
//constexpr size_t MAX_CHARACTERS_IN_CELL = 50;
//constexpr size_t MAX_DIGITS_IN_NUMBER = 3;
//const char END_OF_ROW_TAG[6] = "</tr>";
//
//class HTMLParser {
//	
//	enum class Command {
//		Undefined,
//		Add,
//		Remove,
//		Edit,
//		Print
//	};
//
//	enum ErrorCodes {
//		OK,
//		NullPtrGiven=-1,
//		OpeningError=-2
//	};
//
//	struct Add {
//		int rowNumber = 1;
//		char cellValue[MAX_CHARACTERS_IN_CELL];
//		size_t cellsCount = 0;
//		Add()
//		{
//			rowNumber = 1;
//			cellsCount = 0;
//			cellValue[0] = '\0';
//		}
//		Add(int NumberFormCommand, int cellsFromCommand)
//		{
//			rowNumber = NumberFormCommand;
//			cellsCount = cellsFromCommand;
//			cellValue[0] = '\0';
//		}
//	};
//
//	int openFile(const char* filePath)
//	{
//		if (!filePath)
//			return ErrorCodes::NullPtrGiven;
//
//		std::fstream htmlTable(filePath);
//		if (!htmlTable.is_open())
//			return ErrorCodes::OpeningError;
//	}
//
//	int strcpyWithDenominator(char* dest, const char* source, char denom)
//	{
//		if (!dest || !source)
//			return ErrorCodes::NullPtrGiven;
//		while (*source != denom)
//		{
//			*dest = *source;
//			dest++;
//			source++;
//		}
//		dest++;
//		*dest = '\0';
//	}
//
//	int findCellsCount(const char* arr)
//	{
//		if (!arr)
//			return ErrorCodes::NullPtrGiven;
//
//		size_t cellsCount=0;
//		while (*arr)
//		{
//			if (*arr == START_OF_COMMAND_PARAMETERS)
//				cellsCount++;
//			arr++;
//		}
//		//validations!!! za =0 i >50
//		return cellsCount - 1;
//	}
//
//	int countParts(const char* source, const char* part, const int searchedIndex, int& countedParts, int& lastPositionOfPart)
//	{
//		if (!source || !part)
//			return ErrorCodes::NullPtrGiven;
//		
//		size_t partLenght = 0;
//		int currentPositionOfInd = 0;
//		while (*source)
//		{
//			if (*part)
//			{
//				countedParts++;
//				part -= partLenght;
//				source -= 1;
//				lastPositionOfPart == currentPositionOfInd;
//			}
//
//			if (countedParts == searchedIndex)
//				return 1;
//
//			if (*source == *part)
//			{
//				source++;
//				part++;
//				partLenght++;
//				currentPositionOfInd++;
//			}
//			else
//			{
//				source++;
//				part -= partLenght;
//				currentPositionOfInd++;
//			}
//		}
//		if (*part)
//		{
//			countedParts++;
//			lastPositionOfPart == currentPositionOfInd;
//		}
//
//		return 0;
//	}
//	
//	int positionInFile(int rowNumber, std::ifstream& table)
//	{
//		char buff[MAX_CHARACTERS_IN_ARR];//sizeOfFile
//		int rowsCount = 0;
//		bool isIndexFound = 0;
//		int lastEndOfRow = 0;
//
//		while (table.eof())
//		{
//			table.getline(buff, MAX_CHARACTERS_IN_ARR, END_OF_COMMAND_PARAMETERS);
//			isIndexFound = countParts(buff, END_OF_ROW_TAG, rowNumber - 1, rowsCount, lastEndOfRow);
//			if (isIndexFound)
//				break;
//		}
//
//		if (isIndexFound)
//		{
//			int positionOfInd = -( std::strlen(buff) - lastEndOfRow);
//			table.seekg(positionOfInd, std::ios::cur);
//		}
//		else
//		{
//
//		}
//
//	}
//	int executeAdd(const char* command) 
//	{
//		if (!command)
//			return ErrorCodes::NullPtrGiven;
//
//		//da se iznesat vyv f-ii
//		char rowNumberArr[MAX_DIGITS_IN_NUMBER];
//
//		while (*command)
//		{
//			if (*command == START_OF_COMMAND_PARAMETERS)
//			{
//				command++;
//				strcpyWithDenominator(rowNumberArr, command, END_OF_COMMAND_PARAMETERS);
//				break;
//			}
//		}
//
//		Add addRow(std::atoi(rowNumberArr), findCellsCount(command));
//	}
//
//	int executeCommand(const char* command)
//	{
//		if (!command)
//			return ErrorCodes::NullPtrGiven;
//
//		Command commandType = (Command)*command;
//
//		switch (commandType)
//		{
//		case Command::Add:
//			executeAdd(command);
//			break;
//		case Command::Remove:
//			break;
//		case Command::Edit:
//			break;
//		case Command::Print:
//			break;
//		}
//	}
//public:
//	void parseHTMLTable()
//	{
//		std::cout << "Enter file path." << std::endl;
//		char filePath[MAX_CHARACTERS_IN_ARR];
//		std::cin >> filePath;
//		
//		openFile(filePath);
//		std::cout << "Enter commands." << std::endl;
//		char commandFromConsole[MAX_CHARACTERS_IN_ARR];
//		while (true)
//		{
//			std::cin >> commandFromConsole;
//			executeCommand(commandFromConsole);
//			
//
//
//		}
//
//	}
//};
//
//int main()
//{
//	HTMLParser Parser;
//	Parser.parseHTMLTable();
//}