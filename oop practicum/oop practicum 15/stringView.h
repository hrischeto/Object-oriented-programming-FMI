#pragma once
#include "MyString.h"

class StringView
{
public:
	StringView(const char* beg, const char* end);
	StringView(const char* str);
	StringView(const MyString& str);

	size_t length()const;
	char operator[](int index) const;

	StringView substr(size_t from, size_t length);
	friend std::ostream& operator<<(std::ostream& os, const StringView& str);

private:
	const char* _beg;
	const char* _end;
};