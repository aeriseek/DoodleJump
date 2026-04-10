#include "Game.h"
#include "Config.h"
#include "systems/RenderSystem.h"
#include "systems/GravitySystem.h"
#include "systems/MovementSystem.h"
#include "systems/InputSystem.h"
#include "systems/AnimationSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/CameraSystem.h"
#include "systems/BuildLevelSystem.h"
#include "SFML/Window/Event.hpp"

#include <iostream>

void Game::createPlayer()
{
    _player = _reg.create();
    _reg.addPosition(_player, windowSizeX / 2, windowSizeY / 2);
    _reg.addVelocity(_player, 0.f, 0.f);
    _reg.addInput(_player);
	sf::Texture& tex = AssetManager::GetTexture("resources/player.png");
    sf::Sprite sprite(tex);
	sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
    _reg.addSprite(_player, sprite);
	_reg.gravityAffected[_player] = true;


};

void Game::setBackground()
{
    Entity background = _reg.create();
	sf::Sprite sprite(AssetManager::GetTexture("resources/Background2.png"));
    _reg.addSprite(background, sprite);
}

Game::Game(sf::RenderWindow& gameWin) : _win(&gameWin), _view(sf::FloatRect(0, 0, windowSizeX, windowSizeY))
{
}

void Game::run()
{
	setBackground();
	createPlayer();

	sf::Clock clock;
	
	while (_win->isOpen())
	{
		float dt = clock.restart().asSeconds();
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
	/*	std::cout << "posx : " << _reg.positions[1].x << std::endl;
		std::cout << "posy : " << _reg.positions[1].y << std::endl;
		std::cout << "velx : " << _reg.velocities[1].x << std::endl;
		std::cout << "vely : " << _reg.velocities[1].x << std::endl;*/
		float cameraTop = _view.getCenter().y - (_view.getSize().y / 2.0f);
		BuildLevelSystem(_reg, cameraTop);
		InputSystem(_reg);
		GravitySystem(_reg, dt);
		MovementSystem(_reg, dt);
		CameraSystem(_reg, *_win, _view, _player);
		CollisionSystem(_reg);
		AnimationSystem(_reg);
		RenderSystem(_reg, _win);
		_win->display();
	}
   
}