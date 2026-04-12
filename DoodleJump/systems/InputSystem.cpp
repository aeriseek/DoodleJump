#include "InputSystem.h"

void InputSystem(Register& reg)
{
	for (Entity entity = 0; entity < reg.totalEntities(); ++entity)
	{
		if (reg.hasInput[entity]) {
			reg.inputComponent[entity].movingDirection = 0.f;
			if (sf::Keyboard::isKeyPressed(leftButton)) reg.inputComponent[entity].movingDirection -= 1.f;
			if (sf::Keyboard::isKeyPressed(rightButton)) reg.inputComponent[entity].movingDirection += 1.f;
		}
	}
}