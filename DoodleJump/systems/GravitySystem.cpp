#include "GravitySystem.h"
void GravitySystem(Register& reg, const float dt)
{
	for (Entity entity = playerID; entity < reg.totalEntities(); ++entity)
	{
		if (reg.gravityAffected[entity]) {
			reg.velocities[entity].y += G * dt;
		} 
	}
	
};
