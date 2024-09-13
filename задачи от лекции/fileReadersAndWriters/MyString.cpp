#include "MyString.h"
#pragma warning (disable:4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

static unsigned dataToAllocByStrLen(unsigned strLen)
{
	return std::max(roundToPowerOfTwo(strLen), 16u);
}

MyString::MyString() :MyString("") {}

MyString::MyString(const char* data)
{
	_size = std::strlen(data);
	_cap = dataToAllocByStrLen(_size);

	_data = new char[_cap];
	strcpy(_data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

MyString& MyString::operator+=(const MyString& other)
{
	if (getSize() + other.getSize() + 1 > _cap)
		resize(dataToAllocByStrLen(getSize() + other.getSize()));

	std::strncat(_data, other._data, other.getSize());

	_size = getSize() + other.getSize();

	return *this;
}

size_t MyString::getSize() const
{
	return _size;
}

size_t MyString::getCapacity() const
{
	return _cap - 1;
}

const char* MyString::c_str() const
{
	return _data;
}

const char& MyString::operator[](size_t index) const
{
	return _data[index];
}

 char& MyString::operator[](size_t index)
{
	return _data[index];
}

 MyString operator+(const MyString& lhs, const MyString& rhs)
 {
	 MyString result(lhs.getSize() + rhs.getSize());
	 result += lhs;
	 result += rhs;
	 return result;
 }

 std::ostream& operator<<(std::ostream& os, const MyString& str)
 {
	 return os << str._data;
 }

 std::istream& operator>>(std::istream& is, MyString& str)
 {
	 char buff[1024];
	 is.getline(buff, 1024);

	 size_t buffStringSize = std::strlen(buff);

	 if (str.getCapacity() < buffStringSize)
		 str.resize(dataToAllocByStrLen(buffStringSize));

	 strcpy(str._data, buff);

	 return is;
 }

 MyString::MyString(size_t size)
 {
	 _cap = dataToAllocByStrLen(size);
	 _data = new char[_cap];
	 _size = 0;
	 _data[0] = '\0';
 }

 void MyString::copyFrom(const MyString& other)
 {
	 _cap = other._cap;
	 _data = new char[_cap];
	 _size = other._size;

	 strcpy(_data, other._data);
 }

 void MyString::moveFrom(MyString&& other)
 {
	 _data = other._data;
	 other._data = nullptr;
	 _size = other._size;
	 _cap = other._cap;
	 other._cap = 0;
	 other._size = 0;
 }

 void MyString::free()
 {
	 delete[] _data;
	 _cap = 0;
	 _size = 0;
 }

 void MyString::resize(size_t newCap)
 {
	 char* newData = new char[newCap+1];

	 strcpy(newData, _data);
	 delete[] _data;

	 _data = newData;
	 _cap = newCap;
 }

 bool operator==(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str())== 0;
 }
 bool operator!=(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
 }
 bool operator<(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
 }
 bool operator<=(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
 }
 bool operator>(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
 }
 bool operator>=(const MyString& lhs, const MyString& rhs)
 {
	 return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
 }

 MyString MyString::substr(size_t begin, size_t howMany) const
 {
	 if (begin + howMany > getSize())
		 throw std::length_error("Error, Substr out of range");


	 MyString res(howMany + 1);
	 strncat(res._data, _data + begin, howMany);
	 return res;
 }
