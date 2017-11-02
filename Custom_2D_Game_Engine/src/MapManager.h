#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include "Entity.h"

namespace Engine {
	typedef enum {
		NONE = 0,
		UP = 1,
		DOWN = 2,
		LEFT = 3,
		RIGHT = 4,
		TOP_LEFT = 7,
		TOP_RIGHT = 8,
		BOTTOM_LEFT = 9,
		BOTTOM_RIGHT = 10
	} Direction;

	class MapManager : public sf::Sprite
	{
	public:
		MapManager();
		~MapManager();
	public:
		void Load(std::string filename);
		int CheckCollision(Entity* ent, Direction dir);
	protected:
		std::string m_tileset;
		int m_width = 0;
		int m_height = 0;
		int m_tileWidth = 0;
		int m_tileHeight = 0;
		int* m_MapData;
	private:
		sf::Texture m_texture;
		sf::Image m_tilesetImg;
	};
}