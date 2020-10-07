#pragma once

#include "../engine/State.h"
#include "../engine/Game.h"

namespace Engine {
    class SplashState : public State {
    private:
        GameDataRef _data;
        sf::Text _splashText;
        sf::Text _instructions;
    public:
        SplashState(GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void draw();

        void pause();
        void resume();
    };
}