#include "Flash.h"
#include "Config.h"

namespace Engine {
    Flash::Flash(GameDataRef data) : _data(data) {
        _flashRect = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
        _flashRect.setFillColor(sf::Color(255, 255, 255, 0));
    };

    void Flash::trigger() {
        _flashOn = true;
    }

    void Flash::update(float dt) {
        float currAlpha = _flashRect.getFillColor().a;
        float newAlpha = currAlpha + (_flashOn ? FLASH_SPEED * dt : - FLASH_SPEED * dt);
        if (_flashOn && newAlpha > 255.f) {
            newAlpha = 255.f;
            _flashOn = false;
        } else if (!_flashOn && newAlpha < 0.f) {
            newAlpha = 0.f;
        }

        _flashRect.setFillColor(sf::Color(255, 255, 255, newAlpha));
    }

    void Flash::draw() {
        _data->window.draw(_flashRect);
    }
}