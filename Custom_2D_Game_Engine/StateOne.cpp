#include "stdafx.h"
#include "StateOne.h"
#include "StateTwo.h"

StateOne::StateOne(Engine::data* data) : m_data(data) {
	
}

void StateOne::Init(sf::RenderWindow* window) {
	m_data->entity = new Engine::EntityManager();
	m_data->map = new Engine::MapManager();

	m_rect.setPosition(50, 50);
	m_rect.setSize(sf::Vector2f(64, 64));
	m_rect.setFillColor(sf::Color::Blue);
	m_button.setPosition(300, 300);
	m_button.setFillColor(sf::Color::Green);
	m_button.setSize(sf::Vector2f(100, 100));
	m_data->map->Load("RPG1.map");
	m_data->entity->Add("test1", new TestEntity(m_data));
}

void StateOne::HandleInput(sf::RenderWindow* window) {
	m_time = m_clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_time.asMilliseconds() > 200) {
		m_clock.restart();
		m_data->state->SetState(new StateTwo(m_data));
	}
}

void StateOne::Update(sf::RenderWindow* window) {
	m_data->entity->Update(window);
}

void StateOne::Render(sf::RenderWindow* window) {
	window->draw(*m_data->map);
	window->draw(m_rect);
	window->draw(m_button);
	m_data->entity->Render(window);
}

void StateOne::Destroy(sf::RenderWindow* window) {
	delete m_data->entity;
	delete m_data->map;
}



StateOne::~StateOne()
{
}
