#pragma once

#include "../engine/State.h"
#include "../engine/Game.h"

namespace Engine {
    class MainMenuState : public State {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
    public:
        MainMenuState(GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void draw();

        void pause();
        void resume();
    };
}