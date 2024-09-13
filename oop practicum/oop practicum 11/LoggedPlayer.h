#pragma once
#include "Player.h"
#include "MyString.h"

class LoggedPlayer :
    public Player
{
private:
    MyString password;
};

