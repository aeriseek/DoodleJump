
#include "RenderSystem.h"

void RenderSystem(Register& reg, sf::RenderTarget* target, sf::View& gameView)
{
    target->clear();
    uint32_t totalEntities = reg.totalEntities();


    target->setView(target->getDefaultView()); // tmp
    if (reg.hasSprite[0]) {
        target->draw(reg.sprites[0]);
    }
    target->setView(gameView);

    for (Entity entity = 1; entity < totalEntities; ++entity)
    {
        if (reg.hasSprite[entity])
        {
            if (reg.hasPosition[entity])
                reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);

            target->draw(reg.sprites[entity]);
        }
    }
}