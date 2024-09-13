#pragma once
#include "Player.h"
class Guest :
    public Player
{
private:
    int timeLeftToPlay = 0;
public:
    bool levelUp() override;
};

