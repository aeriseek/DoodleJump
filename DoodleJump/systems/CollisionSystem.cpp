#include "CollisionSystem.h"


bool checkAABB(const sf::FloatRect& platform, const sf::FloatRect& player) { // for player`s legs
	sf::FloatRect legsSensor;
	legsSensor.left = player.left;
	legsSensor.width = player.width;
	legsSensor.top = player.top + player.height - 2.0f;
	legsSensor.height = 4.0f;

	return (platform.left < legsSensor.left + legsSensor.width &&
			platform.left + platform.width > legsSensor.left &&
			platform.top < legsSensor.top + legsSensor.height &&
			platform.top + platform.height > legsSensor.top);
}

void resolveBorders(Register& reg, Entity entity) // left and right border screens
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

void resolveBottomBorder(Register& reg, Entity player, sf::RenderWindow& win)
{
	const sf::View& view = win.getView();
	float bottomViewEdge = view.getCenter().y + (view.getSize().y / 2.0f);
	if (reg.positions[player].y > bottomViewEdge)
		reg.restart();
}

void CollisionSystem(Register& reg, sf::RenderWindow& win)
{
	for (auto& [player, _] : reg.positions)
	{
		if (!reg.hasInput[player]) continue;
		resolveBorders(reg, player);
		resolveBottomBorder(reg, player, win);
		for (auto& [entity, _] : reg.positions)
		{
			if (player == entity || !reg.hasCollision[entity]) continue;
			const sf::FloatRect& bPlayer = reg.sprites[player].getGlobalBounds();
			const sf::FloatRect& bEntity = reg.sprites[entity].getGlobalBounds();

			if (reg.velocities[player].y > 0 && checkAABB(bEntity, bPlayer))
				reg.velocities[player].y = jumpPower;
		}
	}

}


