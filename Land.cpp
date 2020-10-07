#include "Land.h"
#include "Config.h"

namespace Engine {
    Land::Land(GameDataRef data) : _data(data){
        sf::Sprite land1(_data->assets.getTexture("land"));
        sf::Sprite land2(_data->assets.getTexture("land"));
        land1.setPosition(0, SCREEN_HEIGHT - land1.getGlobalBounds().height);
        land2.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT - land2.getGlobalBounds().height);
        _landSprites.push_back(land1);
        _landSprites.push_back(land2);
    };

    const std::vector<sf::Sprite>& Land::getSprites() {
        return _landSprites;
    };

    void Land::moveLand(float dt, float gameSpeed) {
        float movement = gameSpeed * dt;
        for (auto it = _landSprites.begin(); it < _landSprites.end(); ++it) {
            it->move(-movement, 0);
            if (it->getPosition().x < -(it->getGlobalBounds().width))
                it->setPosition(SCREEN_WIDTH-5, SCREEN_HEIGHT - (it->getGlobalBounds().height));
        }
    }

    void Land::drawLand() {
        for (auto it = _landSprites.begin(); it < _landSprites.end(); ++it) {
            _data->window.draw(*it);
        }
    }
}
