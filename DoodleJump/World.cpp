#include "World.h"
#include "Config.h"

void createPlayer(float initPosX, float initPosY)
{
    Entity player = reg.create();
    reg.addPosition(player, windowSizeX / 2, windowSizeY - 50);
    reg.addVelocity(player, 0.f, 0.f);
    reg.addInput(player);
    reg.addSprite(player);
};
