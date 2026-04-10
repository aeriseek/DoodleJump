#include "InputSystem.h"

void InputSystem(Register& reg)
{
	for (auto& itHasInput : reg.hasInputComponent)
	{
		itHasInput.second.left = sf::Keyboard::isKeyPressed(leftButton);
		itHasInput.second.right = sf::Keyboard::isKeyPressed(rightButton);
	}
}