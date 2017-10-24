#include "stdafx.h"
#include "ResourceManager.h"

namespace Engine {
	ResourceManager::ResourceManager()
	{
	}

	void ResourceManager::LoadTexture(std::string name, std::string filename) {
		sf::Texture tex;
		tex.loadFromFile(filename);
		m_textures[name] = tex;
	}
	sf::Texture& ResourceManager::GetTexture(std::string name) {
		return m_textures.at(name);
	}

	void ResourceManager::LoadImage(std::string name, std::string filename) {
		sf::Image img;
		img.loadFromFile(filename);
		m_images[name] = img;
	}
	sf::Image& ResourceManager::GetImage(std::string name) {
		return m_images.at(name);
	}

	void ResourceManager::LoadFont(std::string name, std::string filename) {
		sf::Font font;
		font.loadFromFile(filename);
		m_fonts[name] = font;
	}
	sf::Font& ResourceManager::GetFont(std::string name) {
		return m_fonts.at(name);
	}

	void ResourceManager::LoadSoundBuffer(std::string name, std::string filename) {
		sf::SoundBuffer snd;
		snd.loadFromFile(filename);
		m_soundBuffers[name] = snd;
	}
	sf::SoundBuffer& ResourceManager::GetSoundBuffer(std::string name) {
		return m_soundBuffers.at(name);
	}

	ResourceManager::~ResourceManager()
	{
	}
}