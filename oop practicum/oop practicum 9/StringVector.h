#pragma once
#include "MyString.h"

class StringVector 
{
public:
	StringVector();
	StringVector(size_t capacity);
	StringVector(const StringVector& other);
	StringVector(StringVector&& other) noexcept;

	StringVector& operator=(const StringVector& other);
	StringVector& operator=(StringVector&& other) noexcept;

	~StringVector();

	void push_back(const MyString& element);
	void push_back(MyString&& element);
	void pop_back();

	void insert(int index, const MyString& element); //insert element on index
	void insert(int index, MyString&& element); 
	void erase(int index); //erase elemet at index

	void clear(); //clear data from array
	const MyString& operator[](unsigned index) const;
	MyString& operator[](unsigned index);

	bool empty() const;
	size_t getSize() const;

private:

	void copyFrom(const StringVector& other);
	void moveFrom(StringVector&& other);
	void free();
	void resize(size_t newCap);

	MyString* vector=nullptr;
	size_t size=0;
	size_t capacity=0;
};
