#pragma once
#include <unordered_map>
#include <vector>
#include <bitset>
#include "SFML/Graphics/Sprite.hpp"
#include "components/Position.h"
#include "components/Velocity.h"
#include "components/Input.h"

using Entity = uint32_t;

class Register
{
	Entity nextId = 0;
public:
	std::unordered_map<Entity, Position> positions;
	std::unordered_map<Entity, Velocity> velocities;
	std::unordered_map<Entity, Input> inputComponent;
	std::unordered_map<Entity, sf::Sprite> sprites;

	std::bitset<1024> hasPosition{}; // max 1024 entities for begin
	std::bitset<1024> hasVelocity{};
	std::bitset<1024> hasInput{};
	std::bitset<1024> gravityAffected{};
	std::bitset<1024> hasSprite{};
	std::bitset<1024> hasCollision{};
	Entity create();
	
	uint32_t totalEntities();

	void addPosition(Entity e, float x, float y);

	void addVelocity(Entity e, float x, float y);

	void addInput(Entity e);

	void addSprite(Entity e, sf::Sprite sprite);

	void addCollision(Entity e);
};

