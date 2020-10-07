#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Engine {
    class AssetManager {
    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        std::map<std::string, sf::SoundBuffer> _soundBuffers;
    public:
        void loadTexture(const std::string& name, const std::string& filePath);
        const sf::Texture& getTexture(const std::string& name);

        void loadFont(const std::string& name, const std::string& filePath);
        const sf::Font& getFont(const std::string& name);

        void loadSoundBuffer(const std::string& name, const std::string& filePath);
        const sf::SoundBuffer& getSoundBuffer(const std::string& name);
    };
}