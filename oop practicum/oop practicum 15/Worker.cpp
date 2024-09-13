#include "Worker.h"


Employee* Worker::clone() const
{
	return new Worker(*this);
}

void Worker::addSubordinate(Employee* e)
{

}
 void Worker::print() const
{
	 std::cout << "\t\t-" << name;
}
 Worker::Worker(const MyString& name, unsigned age):Employee(name, age)
 {

 }