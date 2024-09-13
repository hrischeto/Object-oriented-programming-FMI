#include "Worker.h"

Worker::Worker(const MyString& name, unsigned age, unsigned salary, unsigned months):Employee(name, age, salary),workingMonths(months)
{}

Employee* Worker::clone() const
{
	return new Worker(*this);
}
void Worker::print() const
{
	std::cout << "Worker: name " << name << " age " << age << " salary " << salary << " months in company " << workingMonths << std::endl;
}