#include "StringVector.h"

static size_t closestPowerOfAwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
};

StringVector::StringVector() :StringVector(8) {}
StringVector::StringVector(size_t capacity):size(0)
{
	this->capacity = closestPowerOfAwo(capacity);
	vector = new MyString[this->capacity];
}
StringVector::StringVector(const StringVector& other)
{
	copyFrom(other);
}
StringVector::StringVector(StringVector&& other) noexcept
{
	moveFrom(std::move(other));
}


StringVector& StringVector::operator=(const StringVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
StringVector& StringVector::operator=(StringVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

StringVector::~StringVector()
{
	free();
}

void StringVector::push_back(const MyString& element)
{
	if (size + 1 == capacity)
		resize(capacity*2);

	vector[size++] = element;
}
void StringVector::push_back(MyString&& element)
{
	if (size + 1 == capacity)
		resize(capacity * 2);

	vector[size++] = std::move(element);
}

void StringVector::pop_back()
{
		erase(size-1);
}

void StringVector::insert(int index, const MyString& element)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (size + 1 == capacity)
		resize(capacity * 2);

	for (int i = size;i >index;i--)
	{
		vector[i] = vector[i - 1];
	}

	vector[index] = element;
	size++;
}
void StringVector::insert(int index, MyString&& element)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (size + 1 == capacity)
		resize(capacity * 2);

	for (int i = size;i > index;i--)
	{
		vector[i] = vector[i - 1];
	}

	vector[index] = std::move(element);
	size++;
}

void StringVector::erase(int index)
{
	if (index<0 || index>size)
		throw "Invalid index";

	if (!size)
		throw "Vector is already empty!";

	for (int i = index;i < size;i++)
		vector[i] = vector[i + 1];

	size--;
}

void StringVector::clear()
{
	delete[] vector;
	size = 0;
	vector = new MyString[capacity];
}

const MyString& StringVector::operator[](unsigned index) const
{
	if (index<0 || index>size)
		throw "Invalid index";

	return vector[index];
}
MyString& StringVector:: operator[](unsigned index)
{
	if (index<0 || index>size)
		throw "Invalid index";

	return vector[index];
}

bool StringVector::empty() const
{
	return size;
}
size_t StringVector::getSize() const
{
	return size;
}

void StringVector::copyFrom(const StringVector& other)
{
	vector = new MyString[other.capacity];

	for (size_t i = 0; i < other.size; i++)
		vector[i] = other.vector[i];

	size = other.size;
	capacity = other.capacity;
}
void StringVector::moveFrom(StringVector&& other)
{
	vector = other.vector;
	size = other.size;
	capacity = other.capacity;

	other.vector = nullptr;
	other.size = other.capacity = 0;
}
void StringVector::free()
{
	delete[] vector;
	size = capacity = 0;
}

void StringVector::resize(size_t newCap)
{
	MyString* newData = new MyString[newCap];

	for (int i = 0;i < size;i++)
		newData[i] = vector[i];

	delete[] vector;

	vector = newData;
	capacity = newCap;
}

