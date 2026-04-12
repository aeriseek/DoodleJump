#include "AnimationSystem.h"
#include "Config.h"
#include "SFML/Graphics/Sprite.hpp"

void AnimationSystem(Register& reg, const float dt)
{
	//player animation

		if (reg.inputComponent[playerID].movingDirection < 0.f && reg.sprites[playerID].getScale().x != 1.f)
			reg.sprites[playerID].setScale(1.f, 1.f);
		else if (reg.inputComponent[playerID].movingDirection > 0.f && reg.sprites[playerID].getScale().x != -1.f)
			reg.sprites[playerID].setScale(-1.f, 1.f);

		if (reg.inputComponent[playerID].isJumped)
			reg.inputComponent[playerID].jumpAnimTimer = 0.5f;
		

		if (reg.inputComponent[playerID].jumpAnimTimer > 0.f)
		{
			reg.inputComponent[playerID].jumpAnimTimer -= dt;
			reg.sprites[playerID].setTexture(AssetManager::GetTexture(playerJumpedTexture));
		}
		else
		{
			reg.sprites[playerID].setTexture(AssetManager::GetTexture(playerTexture));
		}
}