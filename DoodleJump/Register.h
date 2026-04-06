
#include <unordered_map>
#include <bitset>
#include "components/Position.h"
#include "components/Velocity.h"

using Entity = uint32_t;

class Register
{
	Entity nextId = 0;
public:
	std::unordered_map<Entity, Position> positions;
	std::unordered_map<Entity, Velocity> velocities;

	std::bitset<64> hasPosition;
	std::bitset<64> hasVelocity;

	Entity create();
	

	void addPosition(Entity e, float x, float y);

	void addVelocity(Entity e, float x, float y);


};

