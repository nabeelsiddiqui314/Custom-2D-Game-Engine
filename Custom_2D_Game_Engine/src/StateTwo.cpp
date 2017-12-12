#include "stdafx.h"
#include "StateTwo.h"
#include "StateOne.h"


StateTwo::StateTwo(Engine::data* data) : m_data(data) {
	
}

void StateTwo::Init(sf::RenderWindow& window) {
	m_rect.setPosition(0, 0);
	m_rect.setSize(sf::Vector2f(80, 60));
	m_rect.setFillColor(sf::Color::Red);
}

void StateTwo::HandleInput(sf::RenderWindow& window) {
	m_time = m_clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_time.asMilliseconds() > 200) {
		m_clock.restart();
		m_data->state->SetState(new StateOne(m_data));
	}
}

void StateTwo::Update(sf::RenderWindow& window) {
	
}

void StateTwo::Render(sf::RenderWindow& window) {
	window.draw(m_rect);
}

void StateTwo::Destroy(sf::RenderWindow& window) {
	
}

StateTwo::~StateTwo()
{
}
