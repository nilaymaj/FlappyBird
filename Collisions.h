#pragma once

#include <SFML/Graphics.hpp>

namespace Engine {
    class Collisions {
    public:
        static bool areColliding(const sf::Sprite& s1, const sf::Sprite& s2);
        static bool areScaledColliding(sf::Sprite s1, float scale1, sf::Sprite s2, float scale2);
    };
}