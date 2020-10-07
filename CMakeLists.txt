cmake_minimum_required(VERSION 3.17)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME "FlappyBird")

add_executable(FlappyBird main.cpp engine/State.cpp engine/State.h engine/StateMachine.cpp engine/StateMachine.h engine/AssetManager.cpp engine/AssetManager.h engine/InputManager.cpp engine/InputManager.h engine/Game.cpp engine/Game.h game/Config.h game/SplashState.cpp game/SplashState.h game/MainMenuState.cpp game/MainMenuState.h game/GameState.cpp game/GameState.h game/GameOverState.cpp game/GameOverState.h game/Pipe.cpp game/Pipe.h game/Land.cpp game/Land.h game/Bird.cpp game/Bird.h game/Flash.cpp game/Flash.h game/HUD.cpp game/HUD.h engine/Collision.cpp engine/Collision.h)
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})