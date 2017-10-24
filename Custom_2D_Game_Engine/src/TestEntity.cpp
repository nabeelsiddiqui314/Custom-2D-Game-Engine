#include "stdafx.h"
#include "TestEntity.h"


TestEntity::TestEntity(Engine::data* data) : m_data(data) {
	m_groupId = 1;
	m_gravity = true;
	setSize(sf::Vector2f(50,50));
	setPosition(400,20);
	setFillColor(sf::Color::Blue);
}

bool TestEntity::Update(sf::RenderWindow* window) {
	Entity::Update(window);
	return true;
}

void TestEntity::Collision(Entity* entity) {
	switch (entity->GroupID()) {
	case 1:
		std::cout << "colliding ";
	}
}

TestEntity::~TestEntity() {
	
}
