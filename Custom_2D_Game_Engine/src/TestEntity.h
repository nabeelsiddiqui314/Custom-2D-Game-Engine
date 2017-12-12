#pragma once
#include "Entity.h"
#include "data.h"

class TestEntity : public Engine::Entity
{
public:
	TestEntity(Engine::data* data);
	~TestEntity();
public:
	bool Update(sf::RenderWindow& window);
	void Collision(Entity* entity);
private:
	Engine::data* m_data;
	std::vector<sf::Vector2i> coords = { sf::Vector2i(2,2), sf::Vector2i(50,50) };
};

