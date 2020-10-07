#include "Game.h"
#include "SplashState.h"

#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine {
    Game::Game(int width, int height, std::string title) {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close);
        _data->window.setVerticalSyncEnabled(true);
        _data->machine.addState(StateRef(new SplashState(_data)), false);
        run();
    }

    void Game::run() {
        while (_data->window.isOpen()) {
            _data->machine.processStateChanges();
            float elapsedTime = _clock.getElapsedTime().asSeconds();
            if (elapsedTime < dt) continue;

            while (elapsedTime >= dt) {
                _data->machine.getActiveState()->handleInput();
                _data->machine.getActiveState()->update(dt);
                elapsedTime -= dt;
            }

            _clock.restart();
            _data->machine.getActiveState()->draw();
        }
    }
}