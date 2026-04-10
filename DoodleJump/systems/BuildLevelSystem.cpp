#include <random>
#include "BuildLevelSystem.h"
#include "AssetManager.h"

static std::random_device rd;
static std::mt19937 engine(rd());

std::uniform_int_distribution<> distY(60, 200); // todo

// builds next 2 pages of level
void BuildLevelSystem(Register& reg, float startY)
{
    static float lastGeneratedHeight = startY;
    bool isFirstTime = (reg.hasCollision.count() == 0);
    if (!isFirstTime && startY >= lastGeneratedHeight - 500.f)
    {
        return;
    }
    lastGeneratedHeight = startY;
    sf::Texture& tex = AssetManager::GetTexture("resources/platform.png");
    std::uniform_int_distribution<> countDist(8, 15);
    std::uniform_int_distribution<> distX(tex.getSize().x, windowSizeX - tex.getSize().x);
    
    uint32_t numOfPlatforms = countDist(engine);
    float currentY = isFirstTime ? (float)windowSizeY : startY;
    while (--numOfPlatforms){
        Entity platform = reg.create();
        float x = distX(engine);
        currentY -= distY(engine);
        reg.addPosition(platform, x, currentY);
        
        sf::Sprite sprite(tex);
        sprite.setPosition(x, currentY);
        sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
        reg.addSprite(platform, sprite);
        reg.addCollision(platform);
    }
};