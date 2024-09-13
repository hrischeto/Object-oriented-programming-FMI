#include "Company.h"

int main()
{
	Company hp;

	hp.addWorker();
	hp.addWorker();
	hp.addPaidTrainee();
	hp.addTrainee();

	std::cout << hp.getAvarageSalary() << std::endl;
	hp.print();

	std::cout << hp.twoSum(10);
}