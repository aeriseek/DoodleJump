#include "MovementSystem.h"

void MovementSystem(Register& reg, const float dt)
{
    for (Entity entity = 0; entity < reg.hasVelocity.size(); ++entity)
    {
        if (reg.hasVelocity[entity]) reg.positions[entity] += reg.velocities[entity] * dt;
        if (reg.hasInput[entity]) {
            if (reg.inputComponent[entity].left) reg.positions[entity].x -= playerSpeed * dt;
            if (reg.inputComponent[entity].right) reg.positions[entity].x += playerSpeed * dt;
        }
    }
}