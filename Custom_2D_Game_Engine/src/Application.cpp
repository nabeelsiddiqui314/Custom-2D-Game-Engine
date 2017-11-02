#include "stdafx.h"
#include "Application.h"

namespace Engine {
	Application::Application(int width, int height, std::string title) {
		this->m_window.create(sf::VideoMode(width, height), title);
		m_window.setFramerateLimit(60);
		m_data = new data();
		m_data->state = new StateManager();
		m_data->gui = new GUI(&m_window);
		m_data->state->SetWindow(&m_window);
		m_data->state->SetState(new InitialState(m_data));
		this->Run();
	}

	void Application::Run() {
		while (m_window.isOpen()) {
			sf::Event evnt;
			while (m_window.pollEvent(evnt)) {
				if (evnt.type == sf::Event::Closed) {
					m_window.close();
				}
			}

			m_window.clear();
			while (m_accumulator > m_ups) {
				m_accumulator -= m_ups;
				this->m_data->state->Update();
			}
			m_accumulator += m_clock.restart();
			this->m_data->state->Render();
			m_window.display();
		}
	}


	Application::~Application() {
		delete m_data->state;
		delete m_data->gui;
		delete m_data;
	}
}