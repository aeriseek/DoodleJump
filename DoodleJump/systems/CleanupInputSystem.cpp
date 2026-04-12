#include "CleanupInputSystem.h"


void CleanupInputSystem(Register& reg)
{
	reg.inputComponent[config::playerID].isJumped = false;
}