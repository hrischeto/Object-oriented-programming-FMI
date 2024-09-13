#include "SetByString.h"
#include <sstream>

static unsigned fromCharToNum(char ch)
{
	return ch - '0';
}

SetByString::SetByString(int maxNum, const MyString& str):Bitset(maxNum)
{
	this->str = str;
	fillSet();
}
void SetByString::setString(const MyString& str)
{
	this->str = str;
	fillSet();
}
void SetByString::setAtIndex(char ch, unsigned index)
{
	remove(fromCharToNum(str[index]));
	str[index] = ch;
	add(fromCharToNum(ch));
}

void SetByString::fillSet()
{
	emptySet();

	std::stringstream ss(str.c_str());
	
	while (!ss.eof())
	{
		int current;
		ss >> current;
		add(current);
	}
}