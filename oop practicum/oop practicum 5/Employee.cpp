#include <iostream>
#pragma warning (disable:4996)
#include "employee.h"

Employee::Employee(unsigned id, const char* name, const char* position, double salary)
{
	_id = id;
	setName(name);
	setPosition(position);
	setSalary(salary);
}

double Employee::getSalary() const
{
	return _salary;
}

unsigned Employee::getId() const
{
	return _id;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount > 0)
	{
		_salary = amount;
		return ErrorCode::OK;
	}
	return ErrorCode::InvalidInput;

}

void Employee::setSalary(double salary)
{

	if (salary > 0)
		_salary = salary;
	else
		_salary = 0;
}

void Employee::setName(const char* name)
{
	if (std::strlen(name) > MAX_LEN)
		std::strcpy(_name, "");
	else
		std::strcpy(_name, name);

}

void Employee::setPosition(const char* position)
{
		if (std::strlen(position) > MAX_LEN)
			std::strcpy(_position, "");
		else
			std::strcpy(_position, position);
}

void Employee::print() const
{
	std::cout << _id << " " << _name << " " << _position <<" "<< _salary;
}

void Employee::setId(unsigned id)
{
	_id = id;
}