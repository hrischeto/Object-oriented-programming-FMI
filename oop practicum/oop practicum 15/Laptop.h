#pragma once
#include "Device.h"
class Laptop :
    public Device
{
public:
    Device* clone() const override;
    Laptop(const MyString& str, int price, double weight);

private:
    double weight;

};

