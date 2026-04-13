#include "SoundSystem.h"


void SoundSystem(Register& reg) // works only for player yet
{
	if (reg.inputComponent[config::playerID].isJumped && reg.hasSound[config::playerID])
		reg.soundComponent[config::playerID].playingSound->play();
}