#pragma once
#include "Employee.h"
class Trainee :
    virtual public Employee
{
public:
    Trainee(const MyString& name, unsigned age, unsigned daysLeft);
    Employee* clone() const override;
    void print() const override;

protected:
    unsigned daysLeft = 0;
};

