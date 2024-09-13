#include <iostream>

bool isDigit(char ch) { return ch >= '0' && ch <= '9';}
int convertCharToInt(char ch) { return ch - '0'; }

enum class ErrorCode {
	OK,
	NullptrGiven,
	WrongCharInString,
	EmptyString
};

struct ConvertResult {
	ErrorCode code;
	int result;
};

ConvertResult convertStringToNumber(const char* str)
{
	if (!str)
		return { ErrorCode::NullptrGiven,0 };

	if (!*str)
		return { ErrorCode::EmptyString, 0 };

	int result = 0;

	while(*str)
	{
		if (!isDigit(*str))
			return { ErrorCode::WrongCharInString,0 };

		result *= 10;
		result += convertCharToInt(*str);
		str++;
	}

	return { ErrorCode::OK, result };
}

//int main()
//{
//	ConvertResult res = convertStringToNumber(nullptr);
//	if (res.code == ErrorCode::OK)
//		std::cout << res.result;
//	else
//		std::cout <<(int) res.code;
//}