#pragma once
#include "MyString.h"

class Employee
{
public:
	virtual ~Employee()=default;
	virtual Employee* clone() const;
	virtual void addSubordinate(Employee* e);
	virtual void print() const;
	Employee(const MyString& name, unsigned age);
	virtual size_t getWorkersCount() const;

protected:
	MyString name;
	unsigned age;
};

