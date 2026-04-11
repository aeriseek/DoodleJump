#include "AssetManager.h"


AssetManager* AssetManager::_instance = nullptr;

AssetManager::AssetManager()
{
	if (_instance == nullptr)
	{
		_instance = this;
	}
}

sf::Texture& AssetManager::GetTexture(std::string_view filename)
{
	auto& texMap = _instance->_texturePool;
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
	auto& soundMap = _instance->_soundPool;
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
