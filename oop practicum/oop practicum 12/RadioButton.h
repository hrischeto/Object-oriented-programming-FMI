#pragma once
#include "Control.h"

class RadioButton :
    public Control
{
public:
    RadioButton(unsigned size, Location location, size_t optionsCount);
    Control* clone() const override;
    void setDataDialog() override;
    void setOptionNameAtIndex(const MyString& newText, size_t index);

    RadioButton(const RadioButton& other);
    RadioButton(RadioButton&& other) noexcept;

    RadioButton& operator=(const RadioButton& other);
    RadioButton& operator=(RadioButton&& other);

    ~RadioButton();
private:
    MyString* options;
    size_t count;
    int chosenOption;

    void free();
    void copyFrom(const RadioButton& other);
    void moveFrom(RadioButton&& other);
};

