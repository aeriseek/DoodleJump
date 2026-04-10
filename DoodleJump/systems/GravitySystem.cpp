#include "GravitySystem.h"

#include <iostream>

void GravitySystem(Register& reg, const float dt)
{
	for (auto& itHasVelocity : reg.velocities)
	{
		if (reg.gravityAffected[itHasVelocity.first]) {
			itHasVelocity.second.y += G * dt;
		} 
	}
	
};
