#pragma once
#include "StringPool.h"
#include <iostream>

class ImmutableString
{
public:
	ImmutableString(const char* str);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other) = delete; //this could be implemented in some cases
	~ImmutableString();

	size_t length() const;
	char operator[](size_t index) const;
	const char* c_str() const;

private:
	const char* data;
	size_t len;

	void copyFrom(const ImmutableString& data);
	void free();

	static StringPool pool;
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
