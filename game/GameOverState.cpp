#include <fstream>
#include "GameOverState.h"
#include "GameState.h"
#include "Config.h"

namespace Engine {
    GameOverState::GameOverState(GameDataRef data, unsigned int score)
        : _data(data), _score(score) {};

    void GameOverState::init() {
        _data->assets.loadTexture("game-over_bg", GAME_OVER_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("game-over_title", GAME_OVER_TITLE_FILEPATH);
        _data->assets.loadTexture("game-over_body", GAME_OVER_BODY_FILEPATH);

        _data->assets.loadTexture("platinum-medal", PLATINUM_MEDAL_FILEPATH);
        _data->assets.loadTexture("gold-medal", GOLD_MEDAL_FILEPATH);
        _data->assets.loadTexture("silver-medal", SILVER_MEDAL_FILEPATH);
        _data->assets.loadTexture("bronze-medal", BRONZE_MEDAL_FILEPATH);

        std::string medalTextureName;
        if (_score >= PLATINUM_SCORE) medalTextureName = "platinum-medal";
        else if (_score >= GOLD_SCORE) medalTextureName = "gold-medal";
        else if (_score >= SILVER_SCORE) medalTextureName = "silver-medal";
        else medalTextureName = "bronze-medal";
        _medal.setTexture(_data->assets.getTexture(medalTextureName));
        _medal.setPosition(180, 500);

        _background.setTexture(_data->assets.getTexture("game-over_bg"));
        _title.setTexture(_data->assets.getTexture("game-over_title"));
        _title.setPosition(SCREEN_WIDTH/2.0 - _title.getGlobalBounds().width/2, 200);
        _scoreCard.setTexture(_data->assets.getTexture("game-over_body"));
        _scoreCard.setPosition(SCREEN_WIDTH/2.0 - _scoreCard.getGlobalBounds().width/2, 400);
        _playButton.setTexture(_data->assets.getTexture("main-menu_play"));
        _playButton.setPosition(SCREEN_WIDTH/2.0 - _playButton.getGlobalBounds().width/2, 800);

        _scoreText.setString(std::to_string(_score));
        _scoreText.setFont(_data->assets.getFont("flappy"));
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width, 0);
        _scoreText.setPosition(580, 500);

        unsigned int highScore = readHighScore();
        if (_score > highScore) {
            highScore = _score;
            writeHighScore(highScore);
        };

        _highScoreText.setString(std::to_string(highScore));
        _highScoreText.setFont(_data->assets.getFont("flappy"));
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width, 0);
        _highScoreText.setPosition(580, 600);
    }

    void GameOverState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) _data->window.close();
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R) {
                _data->machine.addState(StateRef(new GameState(_data)));
            }

            if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
                _data->machine.addState(StateRef(new GameState(_data)));
            };
        }
    }

    void GameOverState::update(float dt) {};

    void GameOverState::draw() {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_scoreCard);
        _data->window.draw(_playButton);
        _data->window.draw(_scoreText);
        _data->window.draw(_highScoreText);
        _data->window.draw(_medal);
        _data->window.display();
    }

    unsigned int GameOverState::readHighScore() {
        unsigned int highScore = 0;
        std::ifstream fileReader;
        fileReader.open(HIGH_SCORE_FILEPATH);
        while (!fileReader.eof()) fileReader >> highScore;
        return highScore;
    }

    void GameOverState::writeHighScore(unsigned int score) {
        std::ofstream fileWriter;
        fileWriter.open(HIGH_SCORE_FILEPATH);
        fileWriter << score;
    }

    void GameOverState::pause() {};
    void GameOverState::resume() {};
}
