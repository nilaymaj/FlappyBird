#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/Game.h"

namespace Engine {
    class Flash {
    private:
        GameDataRef _data;
        bool _flashOn = false;
        sf::RectangleShape _flashRect;
    public:
        Flash(GameDataRef data);
        void trigger();
        void update(float dt);
        void draw();
    };
}