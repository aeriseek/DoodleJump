#include "Register.h"

Entity Register::create()
{
	Entity id = nextId++;
	hasPosition[id] = false;
	hasVelocity[id] = false;
	positions[id] = Position(0.f, 0.f);
	velocities[id] = Velocity(0.f, 0.f);
	return id;
}

uint32_t Register::totalEntities()
{
	return nextId;
}

void Register::addPosition(Entity e, float x, float y)
{
	positions[e] = Position(x, y);
	hasPosition[e] = true;
}

void Register::addVelocity(Entity e, float x, float y)
{
	velocities[e] = Velocity(x, y);
	hasVelocity[e] = true;
}

void Register::addInput(Entity e)
{
	hasInputComponent[e] = Input();
}

void Register::addSprite(Entity e, sf::Sprite sprite)
{
	sprites[e] = sprite;
	hasSprite[e] = true;
}