#pragma once
#include "Bitset.h"
#include "MyString.h"

class SetByString :private Bitset
{
public:
    SetByString(int maxNum, const MyString& str);
    void setString(const MyString& str);
    void setAtIndex(char ch, unsigned index);

    using Bitset::contains;
    using Bitset::print;

private:
    MyString str;

    void fillSet();
};

