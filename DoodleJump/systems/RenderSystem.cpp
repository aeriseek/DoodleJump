
#include "RenderSystem.h"

void RenderSystem(Register& reg, sf::RenderTarget* target)
{
    target->clear();
    uint32_t totalEntities = reg.totalEntities();

    for (Entity entity = 0; entity < totalEntities; ++entity)
    {
        if (reg.hasSprite[entity])
        {
            if (reg.hasPosition[entity])
                reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);

            target->draw(reg.sprites[entity]);
        }
    }
}