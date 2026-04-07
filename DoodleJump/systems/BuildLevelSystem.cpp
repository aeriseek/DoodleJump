#include <random>
#include "Register.h"
#include "Config.h"
std::random_device rd;
std::mt19937 engine(rd());
std::uniform_int_distribution<> count(4, 12);
std::uniform_int_distribution<> distX(0, windowSizeX);
std::uniform_int_distribution<> distY(windowSizeY, windowSizeY * 3);

// builds next 2 pages of level
void BuildLevelSystem(Register& reg, float startY)
{
    // static ones
    uint32_t numOfPlatforms = count(engine);
    while (--numOfPlatforms){
        Entity platform = reg.create();
        float x = distX(engine);
        float y = distY(engine) + startY;
        reg.addPosition(platform, x, y);
    }
};