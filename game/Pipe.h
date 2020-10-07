#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../engine/Game.h"

namespace Engine {
    class Pipe {
    private:
        std::vector<sf::Sprite> _pipes;
        std::vector<sf::Sprite> _scoreLines;
        GameDataRef _data;
    public:
        Pipe(GameDataRef data);
        const std::vector<sf::Sprite>& getSprites();
        std::vector<sf::Sprite>& getScoreLines();
        void drawPipes();
        void spawnBottomPipe(int offset);
        void spawnTopPipe(int offset);
        void spawnScoreLine();
        void movePipes(float dt, float gameSpeed);
        void spawnPipePair();
    };
}