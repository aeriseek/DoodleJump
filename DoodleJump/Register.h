#pragma once
#include <unordered_map>
#include <vector>
#include <bitset>
#include "SFML/Graphics/Sprite.hpp"
#include "components/Position.h"
#include "components/Velocity.h"
#include "components/Input.h"
#include "components/SoundComponent.h"
#include "AssetManager.h"
#include "Config.h"

using Entity = uint32_t;

class Register
{
	Entity nextId = 0;
public:
	float levelY;
	std::vector<Entity> freeIDs;
	std::vector<Entity> entitiesToDelete;
	std::vector<Position> positions;
	std::vector<Velocity> velocities;
	std::vector<Input> inputComponent;
	std::vector<sf::Sprite> sprites;
	std::vector<SoundComponent> soundComponent;

	std::bitset<config::maxEntities> hasPosition{}; 
	std::bitset<config::maxEntities> hasVelocity{};
	std::bitset<config::maxEntities> hasInput{};
	std::bitset<config::maxEntities> gravityAffected{};
	std::bitset<config::maxEntities> hasSprite{};
	std::bitset<config::maxEntities> hasCollision{};
	std::bitset<config::maxEntities> hasSound{};


	Register();

	Entity create();
	void remove(Entity entity);
	void createPlayer();
	void setBackground();
	
	uint32_t totalEntities() const;

	void restart();
	
	void addPosition(Entity e, float x, float y);

	void addVelocity(Entity e, float x, float y);

	void addInput(Entity e);

	void addSprite(Entity e, sf::Sprite sprite);

	void addCollision(Entity e);

	void addSound(Entity e, std::string_view filename);
};

