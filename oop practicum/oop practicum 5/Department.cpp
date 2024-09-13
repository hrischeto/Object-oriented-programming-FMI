#include "Department.h"
#include <iostream>
#pragma warning (disable:4996)
Department::Department(const char* name, size_t size)
{
	setName(name);

	if (size < MAX_DEPARTMENT_POSITIONS)
	{
		for (int i = 0;i < size;i++)
		{
			char name[MAX_LEN];
			std::cin >> name;
			_employees[i].setName(name);

			std::cin >> name;
			_employees[i].setPosition(name);

			unsigned id;
			std::cin >> id;
			if (isIdUnique(id))
				_employees[i].setId(id);

			double salary;
			std::cin >> salary;
			_employees[i].updateSalary(salary);
		}
	}
}

Department::Department(const char* name, Employee* employees, size_t size)
{
	setName(name);
	_countOfEmployees = size;
	for (int i = 0;i < _countOfEmployees;i++)
	{
		_employees[i] = employees[i];
	}
	employees = nullptr;
	

}
ErrorCode Department::addEmployee(const Employee& employee)
{
	if (_countOfEmployees >= MAX_DEPARTMENT_POSITIONS)
		return ErrorCode::OutOfBound;

	else {
		_employees[_countOfEmployees] = employee;
		_countOfEmployees++;
		return ErrorCode::OK;
	}

}

int Department::getEmployeeIndexById(unsigned id) const
{
	for (int i = 0;i < _countOfEmployees;i++)
	{
		if (id == _employees[i].getId())
		{
			return i;
		}
	}

	return -1;
}
ErrorCode Department::removeEmployee(unsigned id)
{
	int ind = getEmployeeIndexById(id);
	if (ind == -1)
		return ErrorCode::NotFound;
	else
	{
		for (int i = ind;i < _countOfEmployees - 1;i++)
		{
			_employees[i] = _employees[i + 1];
			_countOfEmployees--;
			return ErrorCode::OK;
		}
	}

}

bool Department::isIdUnique(unsigned id) const
{
	int ind = getEmployeeIndexById(id);
	if (ind == -1)
		return 1;

	else return 0;
}

void Department::setName(const char* name)
{
	if (std::strlen(name) > MAX_LEN)
		std::strcpy(_name, "");
	else
		std::strcpy(_name, name);

}

int main()
{

}