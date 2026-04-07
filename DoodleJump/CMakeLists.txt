cmake_minimum_required (VERSION 3.8)

project ("DoodleJump")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS system window graphics)

include_directories(.)

include_directories(components systems)

add_executable (DoodleJump 
"DoodleJump.cpp" 
"DoodleJump.h" 
"Register.cpp" 
"Register.h" 
"Config.h"
"World.h"
"components/Position.h"
"components/Velocity.h"
"components/Input.h"
"systems/BuildLevelSystem.cpp"
"systems/MovementSystem.cpp"
)

target_link_libraries(DoodleJump sfml-graphics sfml-window sfml-system)

