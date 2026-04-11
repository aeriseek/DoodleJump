#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string_view filename);
	static sf::SoundBuffer& GetSound(std::string_view filename);

private:
	std::unordered_map<std::string, sf::SoundBuffer> _soundPool;
	std::unordered_map<std::string, sf::Texture> _texturePool;

	static AssetManager* _instance;
};