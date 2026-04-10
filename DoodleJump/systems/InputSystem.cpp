#include "InputSystem.h"

void InputSystem(Register& reg)
{
	for (auto& itInput : reg.inputComponent)
	{
			itInput.second.movingDirection = 0.f;
			if (sf::Keyboard::isKeyPressed(leftButton)) itInput.second.movingDirection -= 1.f;
			if (sf::Keyboard::isKeyPressed(rightButton)) itInput.second.movingDirection += 1.f;
	}
}