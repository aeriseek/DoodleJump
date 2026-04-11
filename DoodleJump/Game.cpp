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

Game::Game(sf::RenderWindow& gameWin) : 
	_win(&gameWin), _view(sf::FloatRect(0, 0, windowSizeX, windowSizeY))
{
}

void Game::run()
{
	_reg.setBackground();
	_reg.createPlayer();

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
		float cameraTop = _view.getCenter().y - (_view.getSize().y / 2.0f);
		BuildLevelSystem(_reg, cameraTop);
		InputSystem(_reg);
		GravitySystem(_reg, dt);
		MovementSystem(_reg, dt);
		CameraSystem(_reg, *_win, _view);
		CollisionSystem(_reg, *_win);
		AnimationSystem(_reg);
		RenderSystem(_reg, _win, _view);
		_win->display();
	}
   
}