
#include "RenderSystem.h"
#include "Config.h"

void RenderSystem(Register& reg, sf::RenderTarget* target, sf::View& gameView)
{
    target->clear();
    uint32_t totalEntities = reg.totalEntities();


    target->setView(target->getDefaultView()); // tmp
    if (reg.hasSprite[backgroundID]) {
        target->draw(reg.sprites[backgroundID]);
    }
    target->setView(gameView);

    for (Entity entity = playerID; entity < totalEntities; ++entity)
    {
        if (reg.hasSprite[entity])
        {
            if (reg.hasPosition[entity])
                reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);

            target->draw(reg.sprites[entity]);
        }
    }
}