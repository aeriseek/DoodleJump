cmake_minimum_required (VERSION 3.8)

project ("DoodleJump")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS system window graphics audio)

include_directories(.)

include_directories(components systems)

add_executable (DoodleJump WIN32
"DoodleJump.cpp"  
"Register.cpp" 
"Register.h" 
"Config.h"
"Game.h"
"Game.cpp"
"components/Position.h"
"components/Velocity.h"
"systems/BuildLevelSystem.cpp"
"systems/MovementSystem.cpp"
"systems/RenderSystem.cpp"
"AssetManager.h"
"AssetManager.cpp" 
"systems/RenderSystem.h" 
"systems/GravitySystem.h" 
"systems/GravitySystem.cpp" 
"systems/MovementSystem.h" 
"systems/InputSystem.cpp" 
"systems/InputSystem.h" 
"components/Input.h" 
"systems/AnimationSystem.cpp" 
"systems/AnimationSystem.h" 
"systems/CollisionSystem.h" 
"systems/CollisionSystem.cpp" 
"systems/BuildLevelSystem.h" 
"systems/CameraSystem.h" 
"systems/CameraSystem.cpp" "systems/SoundSystem.h" "systems/SoundSystem.cpp" "components/SoundComponent.h" "systems/CleanupInputSystem.h" "systems/CleanupInputSystem.cpp" "systems/CleanSystem.h" "systems/BoundarySystem.h" "systems/BoundarySystem.cpp")

target_link_libraries(DoodleJump sfml-graphics sfml-window sfml-system sfml-audio)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" 
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

