#include "MyString.h"
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(unsigned v) //static! -> will be discused in the next lecture
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
static unsigned dataToAllocByStringLen(unsigned stringLen)
{
    return std::max(roundToPowerOfTwo(stringLen + 1), 16u);
}

MyString::MyString() : MyString("") {}
MyString::MyString(const char* data)
{
    _size = std::strlen(data);
    _allocatedDataSize = dataToAllocByStringLen(_size);
    _data = new char[_allocatedDataSize];
    std::strcpy(_data, data);
}
MyString::MyString(size_t stringLenght)
{
    _size = 0;
    _allocatedDataSize = dataToAllocByStringLen(stringLenght);
    _data = new char[_allocatedDataSize];
    _data[0] = '\0';
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
    if (this != &other) {
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

size_t MyString::getCapacity() const
{
    return _allocatedDataSize-1;
}
size_t MyString::getSize() const
{
    return _size;
}
const char* MyString::c_str() const
{
    return _data;
}

void MyString::resize(unsigned newAllocatedDataSize)
{
    char* newData = new char[newAllocatedDataSize + 1];
    std::strcpy(newData, _data);
    delete[] _data;
    _data = newData;
    _allocatedDataSize = newAllocatedDataSize;
}

void MyString::free()
{
    delete[] _data;
    _size = _allocatedDataSize = 0;
}
void MyString::copyFrom(const MyString& other)
{
    _allocatedDataSize = other._allocatedDataSize;
    _data = new char[_allocatedDataSize];
    std::strcpy(_data, other._data);
    _size = other._size;

}
void MyString::moveFrom(MyString&& other)
{
    _data = other._data;
    _size = other._size;
    _allocatedDataSize = other._allocatedDataSize;

    other._data = nullptr;
    other._size = 0;
    other._allocatedDataSize = 0;
}

MyString& MyString::operator+=(const MyString& other)
{
    if (_size + other._size + 1 > _allocatedDataSize)
        resize(dataToAllocByStringLen(_size + other._size + 1));

    std::strncat(_data, other._data,other._size);

    _size= getSize() + other.getSize();

    return *this;

}
char& MyString::operator[](size_t index)
{
    return _data[index]; // no security check!!
}
const char& MyString::operator[](size_t index) const
{
    return _data[index]; // no security check!!
}
std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
    return os << obj._data;
}
std::istream& operator>>(std::istream& is, MyString& ref)
{
    char buff[1024];
    is >> buff;
    size_t buffStringSize = std::strlen(buff);

    if (buffStringSize > ref.getCapacity())
        ref.resize(dataToAllocByStringLen(buffStringSize));

    strcpy(ref._data, buff);
    ref._size = buffStringSize;
    return is;
}
MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString result(lhs.getSize() + rhs.getSize());
    result += lhs; // no resize is needed
    result += rhs;
    return result;
}

