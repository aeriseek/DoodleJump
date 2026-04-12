#pragma once
#include "SFML/Audio/Sound.hpp"
#include <memory>

struct SoundComponent
{
	std::unique_ptr<sf::Sound> playingSound;
};