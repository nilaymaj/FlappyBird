#pragma once

#include "../engine/State.h"
#include "../engine/Game.h"

namespace Engine {
    class GameOverState : public State {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _scoreCard;
        sf::Sprite _playButton;
        sf::Sprite _medal;

        sf::Text _scoreText;
        sf::Text _highScoreText;
        unsigned int _score;

        static unsigned int readHighScore();
        static void writeHighScore(unsigned int score);
    public:
        GameOverState(GameDataRef data, unsigned int score);
        void init();

        void handleInput();
        void update(float dt);
        void draw();

        void pause();
        void resume();
    };
}