#include "AnimationSystem.h"
#include "Config.h"

void AnimationSystem(Register& reg, const float dt)
{
	//player animation

		if (reg.inputComponent[playerID].movingDirection < 0.f && reg.sprites[playerID].getScale().x != 1.f)
			reg.sprites[playerID].setScale(1.f, 1.f);
		else if (reg.inputComponent[playerID].movingDirection > 0.f && reg.sprites[playerID].getScale().x != -1.f)
			reg.sprites[playerID].setScale(-1.f, 1.f);

		if (reg.inputComponent[playerID].isJumped)
		{
			reg.inputComponent[playerID].jumpAnimTimer = 0.2f;
			reg.inputComponent[playerID].isJumped = false;
		}
		if (reg.inputComponent[playerID].jumpAnimTimer > 0.f)
		{
			reg.inputComponent[playerID].jumpAnimTimer -= dt;
			// new sprite
		}
		else
		{
			// back to std sprite
		}


	/*for (auto& [entity, sprite] : reg.sprites)
	{
		if (reg.hasInput[entity]) {
			if (reg.inputComponent[entity].movingDirection < 0.f && sprite.getScale().x != 1.f)
				sprite.setScale(1.f, 1.f);
			else if (reg.inputComponent[entity].movingDirection > 0.f && sprite.getScale().x != -1.f)
				sprite.setScale(-1.f, 1.f);
		}
	}*/
}