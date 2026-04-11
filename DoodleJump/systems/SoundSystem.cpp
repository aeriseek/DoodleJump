#include "SoundSystem.h"


void SoundSystem(Register& reg)
{
	if (reg.inputComponent[playerID].isJumped && reg.hasSound[playerID])
	{
		reg.soundComponent[playerID].playingSound.setBuffer(AssetManager::GetSound("resources/sounds/jumpSound.ogg"));
		reg.soundComponent[playerID].playingSound.play();
	}

}