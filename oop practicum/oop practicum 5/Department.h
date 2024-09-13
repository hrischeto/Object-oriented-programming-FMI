#pragma once
#include "employee.h"

constexpr size_t MAX_DEPARTMENT_POSITIONS = 15;
class Department
{
	Employee _employees[MAX_DEPARTMENT_POSITIONS];
	char _name[MAX_LEN];
	unsigned _countOfEmployees;
	
	int getEmployeeIndexById(unsigned id) const;
	bool isIdUnique(unsigned id) const;

public:
	Department() = default;
	Department(const char* name, size_t size);
	Department(const char* name, Employee* employees, size_t size);

	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);

	void setName(const char* name);
	
};