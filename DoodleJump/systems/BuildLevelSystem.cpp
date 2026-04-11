#include <random>
#include "BuildLevelSystem.h"
#include "AssetManager.h"

static std::random_device rd;
static std::mt19937 engine(rd());

std::uniform_int_distribution<> distY(60, 200); // todo

// builds next 2 pages of level
void BuildLevelSystem(Register& reg, float cameraTop)
{
    const float buffer = windowSizeY;
    const float targetY = cameraTop - buffer;

    while (reg.levelY > targetY)
    {
        sf::Texture& tex = AssetManager::GetTexture("resources/textures/platform.png");
        std::uniform_int_distribution<> distX(tex.getSize().x, windowSizeX - (int)tex.getSize().x);

        Entity platform = reg.create();
        float x = (float)distX(engine);

        reg.levelY -= (float)distY(engine);

        reg.addPosition(platform, x, reg.levelY);

        sf::Sprite sprite(tex);
        sprite.setOrigin(tex.getSize().x / 2.f, tex.getSize().y / 2.f);
        sprite.setPosition(x, reg.levelY);

        reg.addSprite(platform, sprite);
        reg.addCollision(platform);
    }
}