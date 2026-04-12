#include "SoundSystem.h"


void SoundSystem(Register& reg) // works only for player yet
{
	if (reg.inputComponent[playerID].isJumped && reg.hasSound[playerID])
		reg.soundComponent[playerID].playingSound.play();
	

}