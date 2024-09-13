#include "Trainee.h"
Trainee::Trainee(const MyString& name, unsigned age, unsigned daysLeft):Employee(name, age, 0), daysLeft(daysLeft)
{

}

Employee* Trainee::clone() const
{
	return new Trainee(*this);
}

void Trainee::print() const
{
	std::cout << "Trainee: name " << name << " age " << age << " days left from training " << daysLeft << std::endl;
}