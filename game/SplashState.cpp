#include "SplashState.h"
#include "Config.h"
#include "MainMenuState.h"
#include <iostream>

namespace Engine {
    SplashState::SplashState(GameDataRef data) : _data(data) {};

    void SplashState::init() {
        _data->assets.loadFont("flappy", FLAPPY_FONT_FILEPATH);
        _splashText.setFont(_data->assets.getFont("flappy"));
        _instructions.setFont(_data->assets.getFont("flappy"));

        _splashText.setString("You actually cloned, built and played this, knowing\n"
                              "this was just another Flappy Bird clone... thanks.");
        _splashText.setCharacterSize(24);
        _instructions.setString("Press Spacebar to flap your wings and enter the game.");
        _instructions.setCharacterSize(22);

        _splashText.setOrigin(_splashText.getGlobalBounds().width/2, _splashText.getGlobalBounds().height/2);
        _splashText.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f - 100);
        _instructions.setOrigin(_instructions.getGlobalBounds().width/2, _instructions.getGlobalBounds().height/2);
        _instructions.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);
    }

    void SplashState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) _data->window.close();
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                _data->machine.addState(StateRef(new MainMenuState(_data)));
        }
    }

    void SplashState::update(float dt) {}

    void SplashState::draw() {
        _data->window.clear(sf::Color::Black);
        _data->window.draw(_splashText);
        _data->window.draw(_instructions);
        _data->window.display();
    }

    void SplashState::pause() {};
    void SplashState::resume() {};
}
