#include "stdafx.h"
#include "TestEntity.h"


TestEntity::TestEntity(Engine::data* data) : m_data(data) {
	m_groupId = 1;
	m_gravity = false;
	setPosition(400,200);
	setSize(sf::Vector2f(50,50));
	setScale(2,2);
	
	m_data->assets->LoadTexture("player", "player.png");
	setTexture(&m_data->assets->GetTexture("player"));
}

bool TestEntity::Update(sf::RenderWindow* window) {
	move(1,1);
	m_data->animation->Animate(*this, sf::Vector2i(30,48), coords, 2, 100);
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
