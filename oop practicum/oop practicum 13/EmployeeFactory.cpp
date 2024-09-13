#include "EmployeeFactory.h"
#include "Trainee.h"
#include "PaidTrainee.h"
#include "Worker.h"

static Employee* getTrainee()
{
	MyString name;
	unsigned age, daysLeft;
	std::cout << "name age days: ";
	std::cin >> name;
	std::cin >> age;
	std::cin >> daysLeft;
	std::cin.ignore();

	return new Trainee(name, age, daysLeft);
}

static Employee* getWorker()
{
	MyString name;
	unsigned age, salary, months;
	std::cout << "name age salary months: ";
	std::cin >> name;
	std::cin >> age;
	std::cin >> salary;
	std::cin >> months;
	std::cin.ignore();

	return new Worker(name, age, salary, months);
}

static Employee* getPaidTrainee()
{
	MyString name;
	unsigned age, salary, rating, months, days;
	std::cout << "name age salary months days rating: ";
	std::cin >> name;
	std::cin >> age;
	std::cin >> salary;
	std::cin >> months;
	std::cin >> days;
	std::cin >> rating;
	std::cin.ignore();

	return new PaidTrainee(name, age, salary, months, days, rating);
}

Employee* EmployeeFactory::employeeFactory(EmployeeType type)
{
	switch (type)
	{
	case EmployeeType::trainee:
		return getTrainee();
	case EmployeeType::worker:
		return getWorker();
	case EmployeeType::paidTrainee:
		return getPaidTrainee();
	}

	return nullptr;
}

