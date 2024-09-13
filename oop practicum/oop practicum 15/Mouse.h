#pragma once
#include "Device.h"
class Mouse :
    public Device
{
public:
    Device* clone() const override;
    Mouse(const MyString& str, int price, double DPI);

private:
    double DPI;
};

