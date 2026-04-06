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
