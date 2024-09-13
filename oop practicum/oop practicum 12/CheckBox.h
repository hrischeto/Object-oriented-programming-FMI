#pragma once
#include "Control.h"
class CheckBox :
    public Control
{
public:
    CheckBox(unsigned size, Location location, const MyString& text);
    Control* clone() const override;
    void setDataDialog() override;
    void setText(const MyString& newText);

private:
    MyString text;
    bool state;
};

