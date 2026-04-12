#include "BoundarySystem.h"
#include "SFML/Graphics/View.hpp"

void BoundarySystem(Register& reg, sf::RenderTarget& win)
{
	const sf::FloatRect& view = win.getView().getViewport();
	for (Entity entity = 0; entity < reg.totalEntities(); ++entity)
	{
		if (reg.hasPosition[entity] &&
			!view.contains(reg.positions[entity].x, reg.positions[entity].y))
	}
}