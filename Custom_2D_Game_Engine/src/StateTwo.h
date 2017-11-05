#pragma once
#include "State.h"
#include "data.h"

class StateTwo : public Engine::State
{
public:
	StateTwo(Engine::data* data);
	~StateTwo();
public:
	void Init(sf::RenderWindow* window);
	void HandleInput(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Engine::data*      m_data;
	sf::RectangleShape m_rect;
	sf::Clock          m_clock;
	sf::Time           m_time;
};

