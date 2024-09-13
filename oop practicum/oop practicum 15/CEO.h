#pragma once
#include "Manager.h"

class CEO :
    public Manager
{
public:
	Employee* clone() const override;
	void print() const override;
	size_t getWorkersCount() const override;
	CEO(const MyString& name, unsigned age);
};

