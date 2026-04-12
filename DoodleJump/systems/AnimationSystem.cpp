#include "AnimationSystem.h"
#include "Config.h"
#include "SFML/Graphics/Sprite.hpp"

void AnimationSystem(Register& reg, const float dt)
{
	//player animation

		if (reg.inputComponent[config::playerID].movingDirection < 0.f && reg.sprites[config::playerID].getScale().x != 1.f)
			reg.sprites[config::playerID].setScale(1.f, 1.f);
		else if (reg.inputComponent[config::playerID].movingDirection > 0.f && reg.sprites[config::playerID].getScale().x != -1.f)
			reg.sprites[config::playerID].setScale(-1.f, 1.f);

		if (reg.inputComponent[config::playerID].isJumped)
			reg.inputComponent[config::playerID].jumpAnimTimer = 0.5f;
		

		if (reg.inputComponent[config::playerID].jumpAnimTimer > 0.f)
		{
			reg.inputComponent[config::playerID].jumpAnimTimer -= dt;
			reg.sprites[config::playerID].setTexture(AssetManager::GetTexture(config::playerJumpedTexture));
		}
		else
		{
			reg.sprites[config::playerID].setTexture(AssetManager::GetTexture(config::playerTexture));
		}
}