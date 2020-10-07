#include "Collisions.h"

namespace Engine {
    bool Collisions::areColliding(const sf::Sprite &s1, const sf::Sprite &s2) {
        sf::Rect<float> rect1 = s1.getGlobalBounds(), rect2 = s2.getGlobalBounds();
        return rect1.intersects(rect2);
    }

    bool Collisions::areScaledColliding(sf::Sprite s1, float scale1, sf::Sprite s2, float scale2) {
        s1.scale(scale1, scale1);
        s2.scale(scale2, scale2);
        sf::Rect<float> rect1 = s1.getGlobalBounds(), rect2 = s2.getGlobalBounds();
        return rect1.intersects(rect2);
    }
}