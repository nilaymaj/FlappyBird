#include "InputManager.h"

namespace Engine {
    sf::Vector2<int> InputManager::getMousePosition(const sf::RenderWindow &window) {
        return sf::Mouse::getPosition(window);
    }

    bool InputManager::isSpriteClicked(const sf::Sprite& sprite, sf::Mouse::Button button, const sf::RenderWindow &window) {
        if (!sf::Mouse::isButtonPressed(button)) return false;
        sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y,
                         sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
        return rect.contains(sf::Mouse::getPosition(window));
    }
}