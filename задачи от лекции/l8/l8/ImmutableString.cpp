#include "ImmutableString.h"
#pragma warning (disable:4996)

StringPool ImmutableString::pool;

ImmutableString::ImmutableString(const char* str)
{
	data = pool.getAllocatedString(str);
	len = std::strlen(str);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	copyFrom(other);
}

ImmutableString::~ImmutableString()
{
	free();
}

size_t ImmutableString::length() const
{
	return len;
}

char ImmutableString::operator[](size_t index) const
{
	return data[index];
}
const char* ImmutableString::c_str() const
{
	return data;
}

void ImmutableString::copyFrom(const ImmutableString& other)
{
	data = pool.getAllocatedString(other.data);
	len = other.len;
}

void ImmutableString::free()
{
	pool.releaseString(data);
	len = 0;
	data = nullptr;
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
	return os << str.c_str();
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

int main()
{
	ImmutableString str1("abc");
	ImmutableString str4("abc");
	ImmutableString str2("abv");
	std::cout << str1 << " " << str4 << " " << str2;
}