#pragma once
#include "SFML/Window/Keyboard.hpp"
#include <cstdint>
#include <string_view>

namespace config {
    inline constexpr int windowSizeX = 600;
    inline constexpr int windowSizeY = 900;

    inline constexpr float playerSpeed = 600.f;
    inline constexpr float jumpPower = -750.f;

    inline constexpr float G = 500.f; // gravity const

    inline constexpr sf::Keyboard::Key leftButton = sf::Keyboard::Left;
    inline constexpr sf::Keyboard::Key rightButton = sf::Keyboard::Right;

    inline constexpr uint32_t backgroundID = 0;
    inline constexpr uint32_t playerID = 1;

    inline constexpr uint32_t maxEntities = 512;

    inline constexpr std::string_view playerTexture = "resources/player.png";
    inline constexpr std::string_view playerJumpedTexture = "resources/player_jumped.png";
    inline constexpr std::string_view backgroundTexture = "resources/textures/Background.png";
    inline constexpr std::string_view jumpSoundPath = "resources/sounds/jumpSound.ogg";
}