#pragma once
#include "SFML/Window/Keyboard.hpp"
#include <cstdint>
const int windowSizeX = 600;
const int windowSizeY = 900;

const float playerSpeed = 600.f;
const float jumpPower = -750.f;

const float G = 500; // gravity const

constexpr sf::Keyboard::Key leftButton = sf::Keyboard::Left;
constexpr sf::Keyboard::Key rightButton = sf::Keyboard::Right;

const uint32_t backgroundID = 0;
const uint32_t playerID = 1;
