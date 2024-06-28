#pragma once
#include "MyString.h"

class LimitReachedException
{
	MyString messege;

public:

	void what()
	{
		std::cout<<messege;
	}

	LimitReachedException(MyString messege):messege(messege){}
};

struct Counter
{
	unsigned useCount = 0;
	unsigned weakCount = 0;

	void removeLimitedPtr()
	{
		useCount--;
		if (useCount == 0)
			weakCount--;
	}
	void removeWeakPtr()
	{
		weakCount--;
	}

	void addLimitedPtr()
	{
		useCount++;
		if (useCount == 1)
			weakCount++;
	}

	void addWeakPtr()
	{
		weakCount++;
	}
};

template <typename T,size_t maxPointers>
class LimitedPtr
{
public:
	template <typename V> friend class WeakPtr;

	LimitedPtr();
	LimitedPtr(T* ptr);

	LimitedPtr(const LimitedPtr<T, maxPointers>& other);
	LimitedPtr& operator=(const LimitedPtr<T, maxPointers>& other);

	LimitedPtr(LimitedPtr<T, maxPointers>&& other) noexcept;
	LimitedPtr& operator=(LimitedPtr<T, maxPointers>&& other) noexcept;

	T& operator*();
	const T& operator*() const;

	T& operator->();
	const T& operator->() const;

	~LimitedPtr();

private:
	T* ptr;
	Counter* counter;

	void free();
	void copyFrom(const LimitedPtr<T, maxPointers>& other);
	void moveFrom(LimitedPtr<T, maxPointers>&& other);
};

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>::LimitedPtr()
{
	ptr = nullptr;
	counter = nullptr;
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>::LimitedPtr(T* ptr)
{
	this->ptr = ptr;

	counter = new Counter();
	counter->addLimitedPtr();
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>::LimitedPtr(const LimitedPtr<T, maxPointers>& other)
{
	copyFrom(other);
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>& LimitedPtr <T, maxPointers>::operator=(const LimitedPtr<T, maxPointers>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>::LimitedPtr(LimitedPtr<T, maxPointers>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>& LimitedPtr<T, maxPointers>::operator=(LimitedPtr<T, maxPointers>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T, size_t maxPointers>
T& LimitedPtr<T, maxPointers>:: operator*()
{
	if (ptr == nullptr)
		throw std::runtime_error("Pointer not set!");

	return *ptr;
}

template <typename T, size_t maxPointers>
const T& LimitedPtr<T, maxPointers>::operator*() const
{
	if (ptr == nullptr)
		throw std::runtime_error("Pointer not set!");

	return *ptr;
}

template <typename T, size_t maxPointers>
T& LimitedPtr<T, maxPointers>::operator->()
{
	return ptr;
}

template <typename T, size_t maxPointers>
const T& LimitedPtr<T, maxPointers>::operator->() const
{
	return ptr;
}

template <typename T, size_t maxPointers>
LimitedPtr<T, maxPointers>::~LimitedPtr()
{
	free();
}

template <typename T, size_t maxPointers>
void LimitedPtr<T, maxPointers>::free()
{
	if (ptr == nullptr && counter == nullptr)
		return;

	counter->removeLimitedPtr();
	if (counter->useCount == 0)
		delete ptr;

	if (counter->weakCount == 0)
		delete counter;
}

template <typename T, size_t maxPointers>
void LimitedPtr<T, maxPointers>::copyFrom(const LimitedPtr<T, maxPointers>& other)
{
	if (other.counter->useCount >= maxPointers)
		throw LimitReachedException("Cannot point anymore pointers!");

	counter = other.counter;

	if (counter)
		counter->addLimitedPtr();

	ptr = other.ptr;
}

template <typename T, size_t maxPointers>
void LimitedPtr<T, maxPointers>::moveFrom(LimitedPtr<T, maxPointers>&& other)
{
	counter = other.counter;
	other.counter = nullptr;

	ptr = other.ptr;
	other.ptr = nullptr;
}