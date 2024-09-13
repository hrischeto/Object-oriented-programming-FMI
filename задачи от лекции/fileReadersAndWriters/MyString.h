#pragma once
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	MyString& operator+=(const MyString& other);

	size_t getSize() const;
	size_t getCapacity() const;
	const char* c_str() const;

	MyString substr(size_t begin, size_t howMany) const;

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);

private:
	explicit MyString(size_t size);

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
	void resize(size_t newCap);

	char* _data = nullptr;
	size_t _size = 0;
	size_t _cap = 0;
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);