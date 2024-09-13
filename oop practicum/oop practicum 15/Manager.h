#pragma once
#include "Employee.h"
class Manager : public Employee
{
public:
	Employee* clone() const override;
	virtual void addSubordinate(Employee* e) override;
	virtual void print() const override;
	size_t getWorkersCount() const override;

	Manager(const MyString& name, unsigned age);

	Manager(const Manager& other);
	Manager(Manager&& other) noexcept;

	Manager& operator=(const Manager& other);
	Manager& operator=(Manager&& other) noexcept;

	~Manager();

protected:
	Employee** subs = nullptr;
	MyString title;
	size_t size = 0;
private:
	
	size_t cap = 0;

	void free();
	void copyFrom(const Manager& other);
	void moveFrom(Manager&& other);

	void resize();
};

