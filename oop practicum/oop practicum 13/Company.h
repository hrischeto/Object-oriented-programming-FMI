#pragma once
#include "Employee.h"

class Company
{
public:
	Company();
	Company(const Company& other);
	Company(Company&& other) noexcept;
	
	Company& operator=(const Company& other);
	Company& operator=(Company&& other) noexcept;

	~Company();

	void addTrainee();
	void addWorker();
	void addPaidTrainee();

	double getAvarageSalary() const;
	bool twoSum(double val) const;

	void print() const;
private:
	void free();
	void copyFrom(const Company& other);
	void moveFrom(Company&& other);
	void resize();

	void sort();

	Employee** data=nullptr;
	size_t size=0;
	size_t cap=0;

	 size_t totalSalary = 0;
};

