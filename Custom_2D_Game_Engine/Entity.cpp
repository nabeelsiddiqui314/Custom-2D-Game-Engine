#include "stdafx.h"
#include "Entity.h"

namespace Engine {
	Entity::Entity() {
		m_exists = true;
	}

	bool Entity::Update() {
		return true;
	}

	void Entity::CheckCollision(Entity* entity) {
		
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