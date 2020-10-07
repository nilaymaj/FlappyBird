#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../engine/Game.h"

namespace Engine {
    class Land {
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _landSprites;
    public:
        Land(GameDataRef data);
        const std::vector<sf::Sprite>& getSprites();
        void drawLand();
        void moveLand(float dt, float gameSpeed);
    };
}