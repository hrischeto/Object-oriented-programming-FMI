#include "PaidTrainee.h"

PaidTrainee::PaidTrainee(const MyString& name, unsigned age, unsigned salary, unsigned months, unsigned days, unsigned rating) :Worker(name, age, salary, months),
Trainee(name, age, days),
Employee(name, age, salary), rating(0)
{
	setRating(rating);
}
void PaidTrainee::setRating(unsigned rating)
{
	if (rating > 100)
		throw std::invalid_argument("Invalid rating!");
	this->rating = rating;
}

Employee* PaidTrainee::clone() const
{
	return new PaidTrainee(*this);
}

void PaidTrainee::print() const
{
	std::cout << "Paid Trainee: name " << name << " age " << age << " salary " << salary << 
		" months in company " << workingMonths << " days left from training "
		<< daysLeft<<" rating "<<rating <<std::endl;
}
