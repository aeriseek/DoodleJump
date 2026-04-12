#pragma once
#include "SFML/Window/Keyboard.hpp"
#include <cstdint>
#include <string>
const int windowSizeX = 600;
const int windowSizeY = 900;

const float playerSpeed = 600.f;
const float jumpPower = -750.f;

const float G = 500; // gravity const

const sf::Keyboard::Key leftButton = sf::Keyboard::Left;
const sf::Keyboard::Key rightButton = sf::Keyboard::Right;

const uint32_t backgroundID = 0; // frist two ids reserved
const uint32_t playerID = 1;

const uint32_t maxEntities = 512; // for bit sets so as it takes 1 cache line in cpu


const std::string playerTexture = "resources/player.png"; 
const std::string playerJumpedTexture = "resources/player_jumped.png";
const std::string backgroundTexture = "resources/textures/Background.png";
const std::string jumpSoundPath = "resources/sounds/jumpSound.ogg";