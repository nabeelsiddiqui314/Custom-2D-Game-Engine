#include "stdafx.h"
#include "EntityManager.h"

namespace Engine {
	EntityManager::EntityManager() {

	}

	void EntityManager::Add(std::string name, Entity* entity) {
		std::unordered_map <std::string, Entity*>::const_iterator found = m_entities.find(name);
		while (found != m_entities.end()) {
			name += "0";
			found = m_entities.find(name);
		}
		m_entities.insert(std::make_pair(name, entity));
	}

	Entity* EntityManager::Get(std::string name) {
		std::unordered_map <std::string, Entity*>::const_iterator found = m_entities.find(name);
		if (found == m_entities.end())
			return NULL;
		else
			return found->second;
	}

	bool EntityManager::Update(sf::RenderWindow* window) {
		std::vector <std::string> RemoveList;
		for (auto& iterator : m_entities) {
			if (iterator.second->Exists()) {
				if (!iterator.second->Update(window)) {
					return false;
				}
			}
			else {
				RemoveList.push_back(iterator.first);
			}

			for (auto& iterator2 : m_entities) {
				if (iterator.first != iterator2.first) {
					if (iterator.second->Exists() && iterator2.second->Exists()) {
						if (iterator.second->CheckCollision(iterator2.second)) {
							iterator.second->Collision(iterator2.second);
						}
					}
				}
			}
		}
		for (auto& iterator : RemoveList) {
			std::unordered_map <std::string, Entity*>::const_iterator found = m_entities.find(iterator);
			if (found != m_entities.end()) {
				delete found->second;
				m_entities.erase(iterator);
			}
		}
		RemoveList.clear();
		return true;
	}

	void EntityManager::Render(sf::RenderWindow* window) {
		for (auto& iterator : m_entities) {
			window->draw(*iterator.second);
		}
	}

	EntityManager::~EntityManager() {
		for (auto& iterator : m_entities) {
			delete iterator.second;
		}
		m_entities.clear();
	}
}