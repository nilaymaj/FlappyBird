#include "MainMenuState.h"
#include "GameState.h"
#include "Config.h"
#include <iostream>

namespace Engine {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {};

    void MainMenuState::init() {
        _data->assets.loadTexture("main-menu_bg", MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("main-menu_title", MAIN_MENU_TITLE_FILEPATH);
        _data->assets.loadTexture("main-menu_play", MAIN_MENU_PLAYBUTTON_FILEPATH);

        _background.setTexture(_data->assets.getTexture("main-menu_bg"));
        _title.setTexture(_data->assets.getTexture("main-menu_title"));
        _playButton.setTexture(_data->assets.getTexture("main-menu_play"));

        _title.setPosition(SCREEN_WIDTH/2.0 - (_title.getGlobalBounds().width)/2, 100);
        _playButton.setPosition(SCREEN_WIDTH/2.0 - (_playButton.getGlobalBounds().width)/2, 800);
    }

    void MainMenuState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) _data->window.close();
            if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
                _data->machine.addState(StateRef(new GameState(_data)));
            };
        }
    }

    void MainMenuState::update(float dt) {};

    void MainMenuState::draw() {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_playButton);
        _data->window.display();
    }

    void MainMenuState::pause() {};
    void MainMenuState::resume() {};
}
