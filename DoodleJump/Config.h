#pragma once
#include "SFML/Window/Keyboard.hpp"
const int windowSizeX = 600;
const int windowSizeY = 900;

const float playerSpeed = 700.f;
const float jumpPower = -750.f;

const float G = 500; // gravity const

constexpr sf::Keyboard::Key leftButton = sf::Keyboard::Left;
constexpr sf::Keyboard::Key rightButton = sf::Keyboard::Right;