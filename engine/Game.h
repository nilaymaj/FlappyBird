#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace Engine {

    struct GameData {
        sf::RenderWindow window;
        StateMachine machine;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    private:
        GameDataRef _data = std::make_shared<GameData>();
        sf::Clock _clock;
        const float dt = 1.f / 60.f;
    public:
        Game(int width, int height, std::string title);
        void run();
    };
}