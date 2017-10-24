#pragma once
#include "Entity.h"
#include <vector>
#include <unordered_map>

namespace Engine {
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();
	public:
		void Add(std::string name, Entity* entity);
		Entity* Get(std::string name);
		bool Update(sf::RenderWindow* window);
		void Render(sf::RenderWindow* window);
	private:
		std::unordered_map <std::string, Entity*> m_entities;
	};
}
