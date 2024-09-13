#include "Company.h"
#include "EmployeeFactory.h"

Company::Company()
{
	size = 0;
	cap = 8;
	data = new Employee * [cap] {nullptr};
	totalSalary = 0;
}

Company::Company(const Company& other)
{
	copyFrom(other);
}

Company::Company(Company&& other) noexcept
{
	moveFrom(std::move(other));
}

Company& Company::operator=(const Company& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Company& Company::operator=(Company&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Company::~Company()
{
	free();
}

void Company::addTrainee()
{
	if (size == cap)
		resize();

	data[size++] = EmployeeFactory::employeeFactory(EmployeeType::trainee);
	sort();
}
void Company::addWorker()
{
	if (size == cap)
		resize();

	data[size] = EmployeeFactory::employeeFactory(EmployeeType::worker);
	totalSalary += data[size++]->getSalary();
	sort();
}
void Company::addPaidTrainee()
{
	if (size == cap)
		resize();

	data[size] = EmployeeFactory::employeeFactory(EmployeeType::paidTrainee);
	totalSalary += data[size++]->getSalary();
	sort();
}

double Company::getAvarageSalary() const
{
	return totalSalary / size;
}


void Company::free()
{
	for (int i = 0;i < cap;i++)
	{
		delete data[i];
	}

	delete[] data;
}

void Company::copyFrom(const Company& other)
{
	data = new Employee * [other.cap] {nullptr};
	size = other.size;
	cap = other.cap;
	totalSalary = other.totalSalary;

	for (int i = 0;i < size;i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void Company::moveFrom(Company&& other)
{
	data = other.data;
	size = other.size;
	cap = other.cap;
	totalSalary = other.totalSalary;

	other.data = nullptr;
	other.size = 0;
	other.cap = 0;
	other.totalSalary = 0;
}
void Company::resize()
{
	Employee** newData = new Employee * [cap *= 2] {nullptr};

	for (int i = 0;i < size;i++)
		newData[i] = data[i];

	delete data;
	data = newData;
}

void Company::sort()
{
	unsigned* sal = new unsigned[size] {0};
	for (int i = 0;i < size;i++)
		sal[i] = data[i]->getSalary();

	for (int i = 0;i < size - 1;i++)
	{
		unsigned minElInd = i;
		for (int j = i + 1;j < size;j++)
		{
			if (sal[j] < sal[minElInd])
				minElInd = j;
		}

		if (minElInd != i)
		{
			std::swap(sal[i], sal[minElInd]);
			std::swap(data[i], data[minElInd]);
		}
	}

	delete[] sal;
}
void Company::print() const
{
	for (int i = 0;i < size;i++)
	{
		std::cout << i+1 << ".";
		data[i]->print();
	}
}

bool Company::twoSum(double val) const
{
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if (j<=i)
				continue;
			unsigned current = data[i]->getSalary() + data[j]->getSalary();
			if (current == val)
				return true;
		}
	}

	return false;
}
