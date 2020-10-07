#include "Bird.h"
#include "Config.h"
#include <cmath>

namespace Engine {
    Bird::Bird(GameDataRef data) : _data(data) {
        _animationFrames.push_back(_data->assets.getTexture("bird1"));
        _animationFrames.push_back(_data->assets.getTexture("bird2"));
        _animationFrames.push_back(_data->assets.getTexture("bird3"));
        _animationFrames.push_back(_data->assets.getTexture("bird4"));

        _currentFrameIndex = 0;
        _sprite.setTexture(_animationFrames.at(_currentFrameIndex));
        _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
        _lastJumpPosition = sf::Vector2<float>(BIRD_LEFT_MARGIN, SCREEN_HEIGHT/3.f);
        _sprite.setPosition(_lastJumpPosition);

        _flapSound.setBuffer(_data->assets.getSoundBuffer("flap"));
    };

    const sf::Sprite & Bird::getSprite() {
        return _sprite;
    }

    void Bird::animate(float dt) {
        int numOfFrames = _animationFrames.size();
        if (_frameClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_SPEED / numOfFrames) {
            _currentFrameIndex = (_currentFrameIndex + 1) % numOfFrames;
            _sprite.setTexture(_animationFrames.at(_currentFrameIndex));
            _frameClock.restart();
        }
    }

    void Bird::flapWings() {
        _lastJumpPosition = _sprite.getPosition();
        _physicsClock.restart();
        _flapSound.play();
    }

    void Bird::update(float dt) {
        float timeSinceJump = _physicsClock.getElapsedTime().asSeconds();
        float newYPosition = BIRD_JUMP_Y_SPEED*timeSinceJump - BIRD_GRAVITY*(timeSinceJump*timeSinceJump)/2;
        _sprite.setPosition(_sprite.getPosition().x, _lastJumpPosition.y - newYPosition);

        float currentYSpeed = BIRD_JUMP_Y_SPEED - BIRD_GRAVITY * timeSinceJump;
        float angle = 0.7 * (180 / M_PI) * std::atan(currentYSpeed / BASE_GAME_SPEED);
        _sprite.setRotation(-angle);
    }

    void Bird::draw() {
        _data->window.draw(_sprite);
    }
}