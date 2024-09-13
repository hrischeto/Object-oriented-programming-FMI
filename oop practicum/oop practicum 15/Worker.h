#pragma once
#include "Employee.h"
class Worker :
    public Employee
{
	virtual Employee* clone() const override;
	virtual void addSubordinate(Employee* e) override;
	virtual void print() const override;
	Worker(const MyString& name, unsigned age);
};

