#include "HUD.h"
#include "Config.h"

namespace Engine {
    HUD::HUD(GameDataRef data) : _data(data) {
        _scoreText.setFont(_data->assets.getFont("flappy"));
        _scoreText.setString(std::to_string(0));
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);
        _scoreText.setCharacterSize(100);
        _scoreText.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/10.f);
    }

    void HUD::updateScore(unsigned int score) {
        _scoreText.setString(std::to_string(score));
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);
    }

    void HUD::draw() {
        _data->window.draw(_scoreText);
    }
}