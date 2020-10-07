#include <iostream>
#include "AssetManager.h"

namespace Engine {
    void AssetManager::loadTexture(const std::string& name, const std::string& filePath) {
        sf::Texture texture;
        if (texture.loadFromFile(filePath)) _textures[name] = texture;
        else std::cout << "Error in loading texture " << name << std::endl;
    }

    const sf::Texture& AssetManager::getTexture(const std::string& name) {
        return _textures.at(name);
    }

    void AssetManager::loadFont(const std::string& name, const std::string& filePath) {
        sf::Font font;
        if (font.loadFromFile(filePath)) _fonts[name] = font;
        else std::cout << "Error in loading font " << name << std::endl;
    }

    const sf::Font & AssetManager::getFont(const std::string &name) {
        return _fonts.at(name);
    }

    void AssetManager::loadSoundBuffer(const std::string& name, const std::string& filePath) {
        sf::SoundBuffer soundBuffer;
        if (soundBuffer.loadFromFile(filePath)) _soundBuffers[name] = soundBuffer;
        else std::cout << "Error in loading sound buffer " << name << std::endl;
    }

    const sf::SoundBuffer & AssetManager::getSoundBuffer(const std::string &name) {
        return _soundBuffers.at(name);
    }
}