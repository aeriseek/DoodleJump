#include "Config.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "Game.h"
#include <filesystem>
#include <iostream>
int main()
{

	std::cout << "Current path is: " << std::filesystem::current_path() << std::endl;

	sf::RenderWindow mainWin(
		sf::VideoMode(windowSizeX, windowSizeY), 
		"Doodle Jump", sf::Style::Close | sf::Style::Titlebar);

	Game game(mainWin);

	game.run();

	
	return 0;
}
