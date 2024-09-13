#include "Employee.h"

Employee* Employee::clone() const
{
	return new Employee(*this);
}

void Employee::addSubordinate(Employee* e)
{

}
void Employee::print() const
{
	std::cout << "\t\t-Employee";
}
Employee::Employee(const MyString& name, unsigned age) :name(name), age(age)
{

}

size_t Employee::getWorkersCount() const
{
	return 0;
}
