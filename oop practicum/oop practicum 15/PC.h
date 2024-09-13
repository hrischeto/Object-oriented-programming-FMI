#pragma once
#include "Device.h"
class PC :
    public Device
{
public:
    Device* clone() const override;
    PC(const MyString& str, int price);
};

