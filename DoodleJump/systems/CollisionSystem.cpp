#include "CollisionSystem.h"


bool checkAABB(const sf::FloatRect& a, const sf::FloatRect& b) {
	return (a.left < b.left + b.width &&
		a.left + a.width > b.left &&
		a.top < b.top + b.height &&
		a.top + a.height > b.top);
}

void resolveBorders(Register& reg, Entity entity)
{
	const sf::FloatRect entityBounds = reg.sprites[entity].getGlobalBounds();
	sf::Vector2f origin = reg.sprites[entity].getOrigin();
	if (entityBounds.left < 0) {
		reg.positions[entity].x = origin.x;
		reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);
	}
	else if (entityBounds.left + entityBounds.width > windowSizeX) {
		reg.positions[entity].x = windowSizeX - (entityBounds.width - origin.x);
		reg.sprites[entity].setPosition(reg.positions[entity].x, reg.positions[entity].y);
	}
}

void CollisionSystem(Register& reg)
{
	for (auto& [player, _] : reg.positions)
	{
		if (!reg.hasInput[player]) continue;
		resolveBorders(reg, player);
		for (auto& [entity, _] : reg.positions)
		{
			if (player == entity || !reg.hasCollision[entity]) continue;
			const sf::FloatRect& bPlayer = reg.sprites[player].getGlobalBounds();
			const sf::FloatRect& bEntity = reg.sprites[entity].getGlobalBounds();

			if (reg.velocities[player].y > 0 && checkAABB(bPlayer, bEntity))
				reg.velocities[player].y = jumpPower;
		}
	}

}


