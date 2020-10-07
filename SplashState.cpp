#include "SplashState.h"
#include "Config.h"
#include "MainMenuState.h"
#include <iostream>

namespace Engine {
    SplashState::SplashState(GameDataRef data) : _data(data) {};

    void SplashState::init() {
        _data->assets.loadTexture("splash_bg", SPLASH_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.getTexture("splash_bg"));
    }

    void SplashState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) _data->window.close();
        }
    }

    void SplashState::update(float dt) {
        float currentTime = _clock.getElapsedTime().asSeconds();
        if (currentTime > SPLASH_SHOW_TIME) {
            _data->machine.addState(StateRef(new MainMenuState(_data)));
        }
    }

    void SplashState::draw() {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

    void SplashState::pause() {};
    void SplashState::resume() {};
}
