#include "Register.h"
#include "SFML/Graphics/RenderTarget.hpp"


RenderSystem(Register& reg, sf::RenderTarget& target)
{
    target.clear();
    uint32_t totalEntities = reg.totalEntities();

    for (Entity entity = 0; entity < totalEntities; ++entity)
    {
        if (reg.hasPosition[entity]) reg.sprites[entity].setPosition(reg.positions[entity]);
        target.draw(reg.sprites[entity]);
    }
}