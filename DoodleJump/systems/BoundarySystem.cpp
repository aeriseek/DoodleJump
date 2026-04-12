#include "BoundarySystem.h"
#include "SFML/Graphics/View.hpp"
#include "Config.h"

void BoundarySystem(Register& reg, sf::RenderTarget& win)
{
    const sf::View& view = win.getView();


    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    sf::FloatRect bounds(
        center.x - size.x / 2.f,
        center.y - size.y / 2.f,
        size.x,
        size.y
    );
	for (Entity entity = playerID + 1; entity < reg.totalEntities(); ++entity)
	{
        if (reg.hasPosition[entity] && reg.positions[entity].y > bounds.top + bounds.height)
			reg.entitiesToDelete.push_back(entity);
	}
}