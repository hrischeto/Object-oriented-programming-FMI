#pragma once
#include "Worker.h"
#include "Trainee.h"

class PaidTrainee : public Worker, public Trainee
{
public:
    PaidTrainee(const MyString& name, unsigned age, unsigned salary, unsigned months, unsigned days, unsigned rating);
    void setRating(unsigned rating);
    Employee* clone() const override;
    void print() const override;

private:
    unsigned rating = 0;
};

