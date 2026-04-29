
#include "RenderSystem.h"
#include "Config.h"

void RenderSystem(Register& reg, sf::RenderTarget* target, sf::View& gameView)
{
    target->clear();
    uint32_t totalEntities = reg.totalEntities();


    target->setView(target->getDefaultView());
    target->draw(reg.sprites[config::backgroundID]); // draw BG picture
    target->setView(gameView);

    for (Entity entity = config::playerID + 1; entity < totalEntities; ++entity)
    {
        if (reg.hasSprite[entity])
        {
            if (reg.hasPosition[entity])
                reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);

            target->draw(reg.sprites[entity]);
        }
    }
    if (reg.hasSprite[config::playerID])
    {
        if (reg.hasPosition[config::playerID])
            reg.sprites[config::playerID].setPosition(reg.positions[config::playerID].x, reg.positions[config::playerID].y);

        target->draw(reg.sprites[config::playerID]);
    } // draw player after all platforms

}