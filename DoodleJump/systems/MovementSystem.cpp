#include "MovementSystem.h"

void MovementSystem(Register& reg, const float dt)
{
    for (Entity entity = 0; entity < reg.positions.size(); ++entity)
    {
        if (reg.hasVelocity[entity]) { // for inertion moves (gravity etc.)
            reg.positions[entity] += reg.velocities[entity] * dt;
        }

        if (reg.hasInput[entity]) { // for input moves
            reg.positions[entity].x += playerSpeed * reg.inputComponent[entity].movingDirection * dt;
        }
    }
}