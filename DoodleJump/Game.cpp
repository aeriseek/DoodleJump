#include "Game.h"
#include "Config.h"

void Game::createPlayer(float initPosX, float initPosY)
{
    Entity player = _reg.create();
    _reg.addPosition(player, windowSizeX / 2, windowSizeY - 50);
    _reg.addVelocity(player, 0.f, 0.f);
    _reg.addInput(player);
    sf::Sprite sprite(AssetManager::GetTexture(""));
    _reg.addSprite(player, sprite);
};

void Game::setBackground()
{

}
