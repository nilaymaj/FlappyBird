#pragma once

#include "../engine/State.h"
#include "../engine/Game.h"

namespace Engine {
    class SplashState : public State {
    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
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