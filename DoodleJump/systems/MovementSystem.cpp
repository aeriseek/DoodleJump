#include "MovementSystem.h"

void MovementSystem(Register& reg, const float dt)
{
    for (uint32_t i = 0; i < reg.hasVelocity.size(); ++i)
        if (reg.hasVelocity[i]) reg.positions[i] += reg.velocities[i] * dt; 
}