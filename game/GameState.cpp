#include "GameState.h"
#include "GameOverState.h"
#include "../engine/Collision.h"
#include "Config.h"
#include <iostream>

namespace Engine {
    GameState::GameState(GameDataRef data) : _data(data) {};

    void GameState::init() {
        srand(time(nullptr));

        _data->assets.loadFont("flappy", FLAPPY_FONT_FILEPATH);
        _data->assets.loadTexture("game_bg", GAME_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("pipe_up", PIPE_UP_FILEPATH);
        _data->assets.loadTexture("pipe_down", PIPE_DOWN_FILEPATH);
        _data->assets.loadTexture("score_line", SCORE_LINE_FILEPATH);
        _data->assets.loadTexture("land", LAND_FILEPATH);

        _data->assets.loadSoundBuffer("hit", HIT_SOUND_FILEPATH);
        _data->assets.loadSoundBuffer("point", POINT_SOUND_FILEPATH);
        _data->assets.loadSoundBuffer("flap", FLAP_SOUND_FILEPATH);

        _data->assets.loadTexture("bird1", BIRD1_FILEPATH);
        _data->assets.loadTexture("bird2", BIRD2_FILEPATH);
        _data->assets.loadTexture("bird3", BIRD3_FILEPATH);
        _data->assets.loadTexture("bird4", BIRD4_FILEPATH);

        _background.setTexture(_data->assets.getTexture("game_bg"));
        _score = 0;

        _pipe = new Pipe(_data);
        _land = new Land(_data);
        _bird = new Bird(_data);
        _flash = new Flash(_data);
        _hud = new HUD(_data);

        _hitSound.setBuffer(_data->assets.getSoundBuffer("hit"));
        _pointSound.setBuffer(_data->assets.getSoundBuffer("point"));
    }

    void GameState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) _data->window.close();
            else if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Q:
                        _playState = PlayState::Crashed;
                        break;
                    case sf::Keyboard::Space:
                        if (_playState == PlayState::Ready) _playState = PlayState::Playing;
                        _bird->flapWings();
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void GameState::update(float dt) {
        float pipeSpawnTime = BASE_PIPE_SPAWN_FREQUENCY * BASE_GAME_SPEED / _gameSpeed;
        // Pipe spawning
        if (_playState == PlayState::Playing) {
            float elapsedTime = _pipeSpawnClock.getElapsedTime().asSeconds();
            if (elapsedTime >= pipeSpawnTime) {
                _pipe->spawnPipePair();
                _pipeSpawnClock.restart();
            }

            _bird->update(dt);
        }

        // Update game speed
        float playTime = _gameSpeedClock.getElapsedTime().asSeconds();
        _gameSpeed = BASE_GAME_SPEED + playTime*3;

        // Crash timer - reuses pipe spawn clock
        if (_playState == PlayState::Crashed) {
            _flash->update(dt);
            if (_pipeSpawnClock.getElapsedTime().asSeconds() > GAME_OVER_APPEAR_TIME) {
                _data->machine.addState(StateRef(new GameOverState(_data, _score)));
            }
            return;
        }

        _pipe->movePipes(dt, _gameSpeed);
        _land->moveLand(dt, _gameSpeed);
        _bird->animate(dt);

        // Check bird does not cross window top border
        if (_bird->getSprite().getPosition().y < 0) {
            birdCrashed();
            return;
        }

        // Check for score lines being crossed
        auto& scoreLines = _pipe->getScoreLines();
        for (auto it = scoreLines.begin(); it < scoreLines.end(); ++it) {
            if (Collision::boundingBoxTest(_bird->getSprite(), *it)) {
                scoreLines.erase(it);
                _pointSound.play();
                ++_score;
            }
        }
        _hud->updateScore(_score);

        // Check collision between bird and ground
        auto& groundSprites = _land->getSprites();
        for (auto& sprite : groundSprites) {
            if (Collision::boundingBoxTest(_bird->getSprite(), sprite)) {
                birdCrashed();
                return;
            }
        }

        // Check collision between bird and pipes
        auto& pipeSprites = _pipe->getSprites();
        for (auto& sprite : pipeSprites) {
            if (Collision::pixelPerfectTest(_bird->getSprite(), sprite)) {
                birdCrashed();
                return;
            }
        }
    };

    void GameState::draw() {
        _data->window.clear();
        _data->window.draw(_background);
        _pipe->drawPipes();
        _land->drawLand();
        _bird->draw();
        _flash->draw();
        _hud->draw();
        _data->window.display();
    }

    void GameState::birdCrashed() {
        _playState = PlayState::Crashed;
        _flash->trigger();
        _pipeSpawnClock.restart();
        _hitSound.play();
    }

    void GameState::pause() {};
    void GameState::resume() {};
}
