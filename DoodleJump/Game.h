#pragma once
#include "AssetManager.h"
#include "Register.h"
#include <unordered_set>


class Game
{
private:

    AssetManager _assets;
    Register _reg;
    void createPlayer(float initPosX, float initPosY);
    void setBackground();
public:
    void run();

};