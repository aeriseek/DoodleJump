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

	std::bitset<64> hasPosition{}; // max 64 entities for begin
	std::bitset<64> hasVelocity{};
	std::bitset<64> hasInput{};
	std::bitset<64> gravityAffected{};
	std::bitset<64> hasSprite{};
	Entity create();
	
	uint32_t totalEntities();

	void addPosition(Entity e, float x, float y);

	void addVelocity(Entity e, float x, float y);

	void addInput(Entity e);

	void addSprite(Entity e, sf::Sprite sprite);

};

