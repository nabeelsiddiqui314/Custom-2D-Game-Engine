#include "stdafx.h"
#include "Entity.h"

namespace Engine {
	Entity::Entity() {
		m_exists = true;
	}

	void Entity::Gravity() {
		if (m_gravity) {
			if (m_GravitySpeed <= 0) {
				m_GravitySpeed = 0.1;
			}
			if (m_GravitySpeed > m_MaxGravitySpeed) {
				m_GravitySpeed = m_MaxGravitySpeed;
			}
			m_GravitySpeed += m_GravityAcceleration;
			std::cout << m_GravitySpeed << std::endl;
		}
		else {
			m_GravitySpeed = 0;
		}
	}

	bool Entity::Update(sf::RenderWindow* window) {
		Gravity();
		move(0, m_GravitySpeed);
		move(m_velocity);
		return true;
	}

	bool Entity::CheckCollision(Entity* entity) {
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	void Entity::Destroy() {
		m_exists = false;
	}

	int Entity::GroupID() const {
		return m_groupId;
	}

	bool Entity::Exists() const {
		return m_exists;
	}

	Entity::~Entity() {

	}
}