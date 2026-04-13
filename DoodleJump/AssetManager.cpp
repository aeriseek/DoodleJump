#include "AssetManager.h"


sf::Texture& AssetManager::GetTexture(std::string_view filename)
{
	auto& texMap = Instance()._texturePool;
	auto pairFound = texMap.find(filename.data());

	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		sf::Texture& texture = texMap[filename.data()];
		texture.loadFromFile(filename.data());
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSound(std::string_view filename)
{
	auto& soundMap = Instance()._soundPool;
	auto pairFound = soundMap.find(filename.data());
	if (pairFound != soundMap.end())
	{
		return pairFound->second;
	}
	else
	{
		sf::SoundBuffer& soundBuffer = soundMap[filename.data()];
		soundBuffer.loadFromFile(filename.data());
		return soundBuffer;
	}
}

AssetManager& AssetManager::Instance()
{
	static AssetManager instance;
	return instance;
}