#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Game.h"

namespace Engine {
    class Bird {
    private:
        sf::Sprite _sprite;
        std::vector<sf::Texture> _animationFrames;
        unsigned int _currentFrameIndex;
        sf::Clock _frameClock;
        sf::Clock _physicsClock;
        sf::Vector2<float> _lastJumpPosition;
        GameDataRef _data;
        sf::Sound _flapSound;
    public:
        Bird(GameDataRef data);
        const sf::Sprite& getSprite();
        void draw();
        void flapWings();
        void update(float dt);
        void animate(float dt);
    };
}