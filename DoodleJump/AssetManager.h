#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "SFML/Graphics/Texture.hpp"

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string_view filename);



private:
	std::unordered_map<std::string, sf::Texture> _texturePool;

	static AssetManager* _instance;
};