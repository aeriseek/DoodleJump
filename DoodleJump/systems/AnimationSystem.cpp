#include "AnimationSystem.h"

void AnimationSystem(Register& reg)
{
	for (auto& [entity, sprite] : reg.sprites)
	{
		if (reg.hasInput[entity]) {
			if (reg.inputComponent[entity].movingDirection < 0.f && sprite.getScale().x != 1.f)
				sprite.setScale(1.f, 1.f);
			else if (reg.inputComponent[entity].movingDirection > 0.f && sprite.getScale().x != -1.f)
				sprite.setScale(-1.f, 1.f);
		}
	}


}