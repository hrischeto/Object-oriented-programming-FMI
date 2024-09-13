#pragma once
#include "Control.h"
class TextBox :
    public Control
{
private:
    MyString text;
public:
    TextBox(unsigned size, Location location, const MyString& text);
    Control* clone() const override;
    void setDataDialog() override;
};

