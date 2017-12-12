#pragma once
#include "State.h"
#include "data.h"

class StateTwo : public Engine::State
{
public:
	StateTwo(Engine::data* data);
	~StateTwo();
public:
	void Init        (sf::RenderWindow& window)	override;
	void HandleInput (sf::RenderWindow& window)	override;
	void Update      (sf::RenderWindow& window)	override;
	void Render      (sf::RenderWindow& window)	override;
	void Destroy     (sf::RenderWindow& window)	override;
private:
	Engine::data*      m_data;
	sf::RectangleShape m_rect;
	sf::Clock          m_clock;
	sf::Time           m_time;
};

