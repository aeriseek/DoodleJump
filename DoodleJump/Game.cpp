#include "Game.h"
#include "Config.h"
#include "systems/RenderSystem.h"
#include "SFML/Window/Event.hpp"

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
    Entity background = _reg.create();
	sf::Sprite sprite(AssetManager::GetTexture("resources/Background2.png"));
    _reg.addSprite(background, sprite);
}

Game::Game(sf::RenderWindow& gameWin) : _win(&gameWin)
{
}

void Game::run()
{
	setBackground();

	while (_win->isOpen())
	{
		sf::Event event;
		while (_win->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_win->close();
				break;
			}


		}
		
		//MovementSystem();
		RenderSystem(_reg, _win);
		_win->display();
	}
   
}