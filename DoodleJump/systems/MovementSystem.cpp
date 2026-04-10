#include "MovementSystem.h"

void MovementSystem(Register& reg, const float dt)
{
    for (auto const& [entity, _] : reg.positions)
    {
        if (reg.hasVelocity[entity]) { // for inertion moves (gravity etc.)
            reg.positions[entity] += reg.velocities[entity] * dt;
        }

        if (reg.hasInput[entity]) { // for input moves
            reg.positions[entity].x += playerSpeed * reg.inputComponent[entity].movingDirection * dt;
        }
    }
}