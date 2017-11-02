#include "stdafx.h"
#include "MapManager.h"

namespace Engine {
	MapManager::MapManager() {
		
	}

	void MapManager::Load(std::string filename) {
		std::string temp;
		std::ifstream mapFile(filename);

		std::getline(mapFile, m_tileset);

		std::getline(mapFile, temp);
		m_tileWidth = std::stoi(temp, nullptr);
		std::getline(mapFile, temp);
		m_tileHeight = std::stoi(temp, nullptr);

		std::getline(mapFile, temp);
		m_width = std::stoi(temp, nullptr);
		std::getline(mapFile, temp);
		m_height = std::stoi(temp, nullptr);

		m_MapData = new int[m_width * m_height];
		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_width; x++) {
				char temp;
				mapFile >> m_MapData[x + y * m_width] >> temp;
			}
		}
		mapFile.close();

		m_texture.create(m_width * m_tileWidth, m_height * m_tileHeight);
		m_tilesetImg.loadFromFile(m_tileset);

		sf::Image tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10, tile11, tile12, tile13, tile14, tile15;

		tile1.create(m_tileWidth, m_tileHeight);
		tile2.create(m_tileWidth, m_tileHeight);
		tile3.create(m_tileWidth, m_tileHeight);
		tile4.create(m_tileWidth, m_tileHeight);
		tile5.create(m_tileWidth, m_tileHeight);
		tile6.create(m_tileWidth, m_tileHeight);
		tile7.create(m_tileWidth, m_tileHeight);
		tile8.create(m_tileWidth, m_tileHeight);
		tile9.create(m_tileWidth, m_tileHeight);
		tile10.create(m_tileWidth, m_tileHeight);
		tile11.create(m_tileWidth, m_tileHeight);
		tile12.create(m_tileWidth, m_tileHeight);
		tile13.create(m_tileWidth, m_tileHeight);
		tile14.create(m_tileWidth, m_tileHeight);
		tile15.create(m_tileWidth, m_tileHeight);

		tile1.copy(m_tilesetImg, 0, 0, sf::IntRect(0, 0, m_tileWidth, m_tileHeight), true);
		tile2.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth, 0, m_tileWidth, m_tileHeight), true);
		tile3.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth * 2, 0, m_tileWidth, m_tileHeight), true);

		tile4.copy(m_tilesetImg, 0, 0, sf::IntRect(0, m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile5.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth, m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile6.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth * 2, m_tileHeight, m_tileWidth, m_tileHeight), true);

		tile7.copy(m_tilesetImg, 0, 0, sf::IntRect(0, 2 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile8.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth, 2 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile9.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth * 2, 2 * m_tileHeight, m_tileWidth, m_tileHeight), true);

		tile10.copy(m_tilesetImg, 0, 0, sf::IntRect(0, 3 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile11.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth, 3 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile12.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth * 2, 3 * m_tileHeight, m_tileWidth, m_tileHeight), true);

		tile13.copy(m_tilesetImg, 0, 0, sf::IntRect(0, 4 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile14.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth, 4 * m_tileHeight, m_tileWidth, m_tileHeight), true);
		tile15.copy(m_tilesetImg, 0, 0, sf::IntRect(m_tileWidth * 2, 4 * m_tileHeight, m_tileWidth, m_tileHeight), true);

		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_width; x++) {
				switch (m_MapData[x + y * m_width]) {
				case 0:
					break;
				case 1:
					m_texture.update(tile1, x * m_tileWidth, y * m_tileHeight);
					break;
				case 2:
					m_texture.update(tile2, x * m_tileWidth, y * m_tileHeight);
					break;
				case 3:
					m_texture.update(tile3, x * m_tileWidth, y * m_tileHeight);
					break;
				case 4:
					m_texture.update(tile4, x * m_tileWidth, y * m_tileHeight);
					break;
				case 5:
					m_texture.update(tile5, x * m_tileWidth, y * m_tileHeight);
					break;
				case 6:
					m_texture.update(tile6, x * m_tileWidth, y * m_tileHeight);
					break;
				case 7:
					m_texture.update(tile7, x * m_tileWidth, y * m_tileHeight);
					break;
				case 8:
					m_texture.update(tile8, x * m_tileWidth, y * m_tileHeight);
					break;
				case 9:
					m_texture.update(tile9, x * m_tileWidth, y * m_tileHeight);
					break;
				case 10:
					m_texture.update(tile10, x * m_tileWidth, y * m_tileHeight);
					break;
				case 11:
					m_texture.update(tile11, x * m_tileWidth, y * m_tileHeight);
					break;
				case 12:
					m_texture.update(tile12, x * m_tileWidth, y * m_tileHeight);
					break;
				case 13:
					m_texture.update(tile13, x * m_tileWidth, y * m_tileHeight);
					break;
				case 14:
					m_texture.update(tile14, x * m_tileWidth, y * m_tileHeight);
					break;
				case 15:
					m_texture.update(tile15, x * m_tileWidth, y * m_tileHeight);
					break;

				}
			}
		}
		setTexture(m_texture);
	}

	int MapManager::CheckCollision(Entity* ent, Direction dir) {
		int x = (int)(ent->getPosition().x + ent->getGlobalBounds().width / 2) / m_tileWidth;
		int y = (int)(ent->getPosition().y + ent->getGlobalBounds().height / 2) / m_tileHeight;

		switch (dir)
		{
		case LEFT:
			x = (int)(ent->getPosition().x + ent->getGlobalBounds().width) / m_tileWidth;
			y = (int)(ent->getPosition().y + ent->getGlobalBounds().height / 2) / m_tileHeight;
			break;
		case RIGHT:
			x = (int)(ent->getPosition().x) / m_tileWidth;
			y = (int)(ent->getPosition().y + ent->getGlobalBounds().height / 2) / m_tileHeight;
			break;
		case UP:
			x = (int)(ent->getPosition().x + ent->getGlobalBounds().width / 2) / m_tileWidth;
			y = (int)(ent->getPosition().y) / m_tileHeight;
			break;
		case DOWN:
			x = (int)(ent->getPosition().x + ent->getGlobalBounds().width / 2) / m_tileWidth;
			y = (int)(ent->getPosition().y + ent->getGlobalBounds().height) / m_tileHeight;
			break;
		case TOP_LEFT:
			x = (int)(ent->getPosition().x + ent->getGlobalBounds().width) / m_tileWidth;
			y = (int)(ent->getPosition().y) / m_tileHeight;
			break;
		case TOP_RIGHT:
			x = (int)(ent->getPosition().x) / m_tileWidth;
			y = (int)(ent->getPosition().y) / m_tileHeight;
			break;
		case BOTTOM_LEFT:
			x = (int)(ent->getPosition().x + ent->getGlobalBounds().width) / m_tileWidth;
			y = (int)(ent->getPosition().y + ent->getGlobalBounds().height) / m_tileHeight;
			break;
		case BOTTOM_RIGHT:
			x = (int)(ent->getPosition().x) / m_tileWidth;
			y = (int)(ent->getPosition().y + ent->getGlobalBounds().height) / m_tileHeight;
			break;
		}
		return m_MapData[x + y * m_width];
	}

	MapManager::~MapManager() {
		delete m_MapData;
	}
}