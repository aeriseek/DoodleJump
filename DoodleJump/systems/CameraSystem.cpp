
#include "CameraSystem.h"


void CameraSystem(Register& reg, sf::RenderWindow& win, sf::View& view)
{
	float playerY = reg.positions[config::playerID].y;
	float currentCenterY = view.getCenter().y;
	if (playerY < currentCenterY) // only up
		view.setCenter(view.getCenter().x, playerY);
	
	win.setView(view);
}