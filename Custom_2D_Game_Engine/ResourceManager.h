#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <map>

namespace Engine {
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();
	public:
		void LoadTexture(std::string name, std::string filename);
		sf::Texture& GetTexture(std::string name);

		void LoadImage(std::string name, std::string filename);
		sf::Image& GetImage(std::string name);

		void LoadFont(std::string name, std::string filename);
		sf::Font& GetFont(std::string name);

		void LoadSoundBuffer(std::string name, std::string filename);
		sf::SoundBuffer& GetSoundBuffer(std::string name);
	private:
		std::map<std::string, sf::Texture> m_textures;
		std::map<std::string, sf::Image> m_images;
		std::map<std::string, sf::Font> m_fonts;
		std::map<std::string, sf::SoundBuffer> m_soundBuffers;
	};
}