#include "Manager.h"
Employee* Manager::clone() const
{
	return new Manager(*this);
}
void Manager::addSubordinate(Employee* e)
{
	if (size == cap)
		resize();

	subs[size++] = e;
}
void Manager::print() const
{
	for (int i = 0;i < size;i++)
	{
		subs[i]->print();
		std::cout << " " << i + 1;
	}
}
Manager::Manager(const MyString& name, unsigned age):Employee(name, age)
{
	size = 0;
	cap = 4;
	subs = new Employee * [cap] {nullptr};
}

Manager::Manager(const Manager& other):Employee(other)
{
	copyFrom(other);
}
Manager::Manager(Manager&& other) noexcept:Employee(std::move(other))
{
	moveFrom(std::move(other));
}

Manager& Manager::operator=(const Manager& other)
{
	if (this != &other)
	{
		Employee::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
Manager& Manager::operator=(Manager&& other) noexcept
{
	if (this != &other)
	{
		Employee::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Manager::~Manager()
{
	free();
}

void Manager::free()
{
	for (int i = 0;i < cap;i++)
	{
		delete subs[i];
	}

	delete[] subs;
}

void Manager::copyFrom(const Manager& other)
{
	subs = new Employee * [other.cap] {nullptr};
	size = other.size;
	cap = other.cap;

	for (int i = 0;i < size;i++)
	{
		subs[i] = other.subs[i]->clone();
	}
}
void Manager::moveFrom(Manager&& other)
{
	subs = other.subs;
	size = other.size;
	cap = other.cap;

	other.subs = nullptr;
	other.size = other.cap = 0;


}

void Manager::resize()
{
	Employee** newData = new Employee * [cap *= 2] {nullptr};

	for (int i = 0;i < size;i++)
	{
		newData[i] = subs[i];
	}

	delete[] subs;
	subs = newData;
}

size_t Manager::getWorkersCount() const
{

	return size;
}