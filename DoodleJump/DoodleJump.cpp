#include "DoodleJump.h"
#include "Config.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/ContextSettings.hpp"
#include "SFML/Window/Event.hpp"

int main()
{

	sf::RenderWindow mainWin(sf::VideoMode(windowSizeX, windowSizeY), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar);


	while (mainWin.isOpen())
	{
		sf::Event event;
		while (mainWin.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mainWin.close();
				break;
			}

		
		}


	}


	
	return 0;
}
