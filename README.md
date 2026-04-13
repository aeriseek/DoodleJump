# Doodle Jump Clone (MVP)

![Game Demo] (DoodleJump/screenshots/Game.png)

A high-performance C++ remake of the classic Doodle Jump game, built using a custom Entity Component System (ECS) architecture and SFML.

This project was developed to explore Data-Oriented Design and high-performance game engine architecture.

🔹 Features

Custom ECS Engine: High-speed entity management using bitsets and SoA (Structure of Arrays).

Infinite Procedural Generation: Dynamic platform spawning and cleanup.

Physics-based Gameplay: Realistic gravity, jumping, and screen wrapping.

Data-Oriented: Components are cache-aligned to maximize CPU efficiency.

Asset Management: Centralized singleton for optimized texture and sound loading.

🔹 Screenshots



Core Systems:
GravitySystem: Handles constant acceleration.

MovementSystem: Updates positions based on velocity and input.

CollisionSystem: Precise AABB collision for "feet-only" jumping.

CameraSystem: Smooth vertical-only camera tracking.

BoundarySystem: Screen-wrap (teleport) for the player and cleanup for platforms.

🔹 Technologies
C++17/20: inline constexpr, std::string_view, std::bitset.

SFML 2.6.x: Rendering, Audio, and Window management.

CMake: Cross-platform build system.

🔹 Build (CMake + SFML)
Requirements
Windows / Linux

Compiler with C++17 support

SFML 2.6.x

Setup
Clone the repository:

Bash
git clone https://github.com/your-username/DoodleJump.git
cd DoodleJump
Create build directory:

Bash
mkdir build && cd build
Configure and build:

Bash
cmake ..
cmake --build .
Project Structure
components/: Pure data structures (Position, Velocity, etc.).

systems/: Logic handlers that iterate over components.

resources/: Textures and sounds (ensure these are in the same folder as the executable).
