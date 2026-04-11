#include "Config.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "Game.h"

int WinMain()
{


	sf::RenderWindow mainWin(
		sf::VideoMode(windowSizeX, windowSizeY), 
		"Doodle Jump", sf::Style::Close | sf::Style::Titlebar);

	Game game(mainWin);

	game.run();

	
	return 0;
}
