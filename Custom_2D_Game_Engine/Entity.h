#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "GUI.h"

namespace Engine {
	class Entity : public sf::RectangleShape
	{
	public:
		Entity();
		~Entity();
	public:
		virtual bool Update();
		virtual void CheckCollision(Entity* entity);
		void Destroy();

		int GroupID() const;
		bool Exists() const;
	protected:
		int m_groupId;
		bool m_exists;
	private:

	};
}

