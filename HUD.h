#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

namespace Engine {
    class HUD {
    private:
        GameDataRef _data;
        sf::Text _scoreText;
    public:
        HUD(GameDataRef data);
        void updateScore(unsigned int score);
        void draw();
    };
}