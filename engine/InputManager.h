#pragma once

#include <SFML/Graphics.hpp>

namespace Engine {
    class InputManager {
    public:
        bool isSpriteClicked(const sf::Sprite& sprite, sf::Mouse::Button button, const sf::RenderWindow& window);
        sf::Vector2<int> getMousePosition(const sf::RenderWindow& window);
    };
}