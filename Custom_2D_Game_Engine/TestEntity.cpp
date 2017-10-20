#include "stdafx.h"
#include "TestEntity.h"


TestEntity::TestEntity(Engine::data* data) : m_data(data) {
	setSize(sf::Vector2f(50,50));
	setPosition(400,20);
	setFillColor(sf::Color::Blue);
}

bool TestEntity::Update() {
	Entity::Update();
	return true;
}

TestEntity::~TestEntity() {

}
