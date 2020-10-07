#include "Pipe.h"
#include "Config.h"
#include <iostream>

namespace Engine {
    Pipe::Pipe(GameDataRef data) : _data(data) {};

    void Pipe::drawPipes() {
        for (auto& pipeSprite : _pipes) {
            _data->window.draw(pipeSprite);
        }

        for (auto& sprite : _scoreLines) {
            _data->window.draw(sprite);
        }
    }

    const std::vector<sf::Sprite>& Pipe::getSprites() {
        return _pipes;
    }

    std::vector<sf::Sprite>& Pipe::getScoreLines() {
        return _scoreLines;
    }

    void Pipe::spawnTopPipe(int offset) {
        sf::Sprite pipeSprite(_data->assets.getTexture("pipe_down"));
        float defaultVertPosition = PIPE_GAP_VERT_MARGIN - pipeSprite.getGlobalBounds().height;
        pipeSprite.setPosition(SCREEN_WIDTH, defaultVertPosition + offset);
        _pipes.push_back(pipeSprite);
    }

    void Pipe::spawnBottomPipe(int offset) {
        sf::Sprite pipeSprite(_data->assets.getTexture("pipe_up"));
        float defaultVertPosition = PIPE_GAP_VERT_MARGIN + PIPE_GAP_HEIGHT;
        pipeSprite.setPosition(SCREEN_WIDTH, defaultVertPosition + offset);
        _pipes.push_back(pipeSprite);
    }

    void Pipe::spawnScoreLine() {
        sf::Sprite lineSprite(_data->assets.getTexture("score_line"));
        float pipeWidth = _data->assets.getTexture("pipe_up").getSize().x;
        float birdWidth = _data->assets.getTexture("bird1").getSize().x;
        lineSprite.setPosition(SCREEN_WIDTH + pipeWidth + 0.9 * birdWidth, 0);
        _scoreLines.push_back(lineSprite);
    }

    void Pipe::spawnPipePair() {
        int landHeight = _data->assets.getTexture("land").getSize().y;
        int offsetRange = SCREEN_HEIGHT - landHeight - 2*PIPE_GAP_VERT_MARGIN - PIPE_GAP_HEIGHT;
        int yOffset = rand() % offsetRange;
        spawnTopPipe(yOffset);
        spawnBottomPipe(yOffset);
        spawnScoreLine();
    }

    void Pipe::movePipes(float dt, float gameSpeed) {
        float movement = gameSpeed * dt;

        for (auto it = _pipes.begin(); it < _pipes.end(); ++it) {
            it->move(-movement, 0);
            if (it->getPosition().x < - it->getGlobalBounds().width)
                _pipes.erase(it);
        }

        for (auto it = _scoreLines.begin(); it < _scoreLines.end(); ++it) {
            it->move(-movement, 0);
        }
    }
}