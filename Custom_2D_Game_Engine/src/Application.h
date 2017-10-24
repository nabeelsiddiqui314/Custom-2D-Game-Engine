#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "InitialState.h"
#include "StateManager.h"
#include "data.h"

namespace Engine {
	class Application
	{
	public:
		Application(int width, int height, std::string title);
		~Application();
	public:
		void Run();
	private:
		sf::RenderWindow m_window;
		sf::Clock m_clock;
		sf::Time m_accumulator = sf::Time::Zero;
		sf::Time m_ups = sf::seconds(1.f / 60.f);
		data* m_data;
	};
}