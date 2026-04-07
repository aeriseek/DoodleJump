#pragma once
#include "Register.h"
#include <unordered_set>


class World
{
private:
    Register reg;
    void createPlayer(float initPosX, float initPosY);
public:
    void run();

};