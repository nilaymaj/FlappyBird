#pragma once

#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Flash.h"
#include "HUD.h"
#include "Config.h"
#include "Collisions.h"

namespace Engine {
    class GameState : public State {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Clock _pipeSpawnClock;
        sf::Clock _gameSpeedClock;
        PlayState _playState = PlayState::Ready;
        unsigned int _score;
        float _gameSpeed = BASE_GAME_SPEED;

        Pipe *_pipe;
        Land *_land;
        Bird *_bird;
        Flash *_flash;
        HUD *_hud;

        sf::Sound _hitSound;
        sf::Sound _pointSound;

        void birdCrashed();

    public:
        GameState(GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void draw();

        void pause();
        void resume();
    };
}