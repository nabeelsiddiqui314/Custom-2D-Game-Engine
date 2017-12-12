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
	void Init        (sf::RenderWindow& window)	override;
	void HandleInput (sf::RenderWindow& window)	override;
	void Update      (sf::RenderWindow& window)	override;
	void Render      (sf::RenderWindow& window)	override;
	void Destroy     (sf::RenderWindow& window)	override;
private:
	Engine::data*      m_data;
	sf::RectangleShape m_rect;
	sf::RectangleShape m_button;
	Engine::Particle*  m_particle;
	sf::Clock          m_clock;
	sf::Time           m_time;
	sf::View           m_view;
};