#pragma once
#include "Employee.h"

class EmployeeFactory
{
public:
	static Employee* employeeFactory(EmployeeType type);
};

