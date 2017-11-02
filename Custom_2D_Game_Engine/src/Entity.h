#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine {
	class Entity : public sf::RectangleShape
	{
	public:
		Entity();
		~Entity();

	public:
		void Gravity();
		virtual bool Update(sf::RenderWindow* window);
		bool CheckCollision(Entity* entity);
		virtual void Collision(Entity* ent) {}
		void Destroy();

		int GroupID() const;
		bool Exists() const;

	protected:
		int m_groupId; // Every Entity has a unique id
		bool m_exists;

		sf::Vector2f m_velocity;
		float m_speed;

		bool m_gravity;
		float m_GravityAcceleration = 1.1;
		float m_GravitySpeed = 2.5;
		float m_MaxGravitySpeed = 5;

		int hp;
		int attackDamage;
	};
}

