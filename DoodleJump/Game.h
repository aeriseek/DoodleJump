#pragma once
#include "AssetManager.h"
#include "Register.h"
#include <unordered_set>
#include "SFML/Graphics/RenderWindow.hpp"


class Game
{
private:
    sf::RenderWindow* _win;
    sf::View _view;
    Entity _player;
    AssetManager _assets;
    Register _reg;
    void createPlayer();
    void setBackground();
public:
    Game(sf::RenderWindow& gameWin);
    void run();

};