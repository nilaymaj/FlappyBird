cmake_minimum_required(VERSION 3.17)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME "FlappyBird")

add_executable(FlappyBird main.cpp State.cpp State.h StateMachine.cpp StateMachine.h AssetManager.cpp AssetManager.h InputManager.cpp InputManager.h Game.cpp Game.h Config.h SplashState.cpp SplashState.h MainMenuState.cpp MainMenuState.h GameState.cpp GameState.h GameOverState.cpp GameOverState.h Pipe.cpp Pipe.h Land.cpp Land.h Bird.cpp Bird.h Flash.cpp Flash.h HUD.cpp HUD.h Collision.cpp Collision.h)
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})