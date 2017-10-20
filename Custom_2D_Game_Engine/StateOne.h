#pragma once
#include "State.h"
#include "data.h"
#include "Particle.h" 
#include "Entity.h"
#include "TestEntity.h"

class StateOne : public Engine::State
{
public:
	StateOne(Engine::data* data);
	~StateOne();
public:
	void Init(sf::RenderWindow* window);
	void HandleInput(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Engine::data* m_data;
	sf::RectangleShape m_rect;
	sf::RectangleShape m_button;
	Engine::Particle* m_particle;
	sf::Clock m_clock;
	sf::Time m_time;
	Engine::Entity* ent;
};