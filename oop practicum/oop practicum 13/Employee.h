#pragma once
#include "MyString.h"
enum class EmployeeType {
	worker,
	trainee, 
	paidTrainee
};

class Employee
{
public:
	Employee(const MyString& name, unsigned age, unsigned salary) :name(name), age(age), salary(salary) {};
	virtual ~Employee()=default;
	virtual Employee* clone() const=0;
	virtual unsigned getSalary() const { return salary; };
	virtual void print() const = 0;

protected:
	MyString name;
	unsigned age;
	unsigned salary;
};
