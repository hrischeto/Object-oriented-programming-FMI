#include "CEO.h"

Employee* CEO::clone() const
{
	return new CEO(*this);
}

void CEO::print() const
{
	std::cout << "-CEO:" << std::endl;
	for (int i = 0;i < size;i++)
	{
		std::cout << "\t-Manager"<<i+1<<":" << std::endl;
		subs[i]->print();
	}
}
CEO::CEO(const MyString& name, unsigned age) :Manager(name, age)
{
}
size_t CEO::getWorkersCount() const
{
	int subCount = size;
	for (int i = 0;i < size;i++)
	{
		subCount += subs[i]->getWorkersCount();
	}
	return subCount;
}