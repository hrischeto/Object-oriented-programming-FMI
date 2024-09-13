#pragma once
#include "Employee.h"
class Worker :
   virtual public Employee
{
public:
    Worker(const MyString& name, unsigned age, unsigned salary, unsigned months);
    Employee* clone() const override;
    void print() const override;

protected:
    unsigned workingMonths = 0;
};

