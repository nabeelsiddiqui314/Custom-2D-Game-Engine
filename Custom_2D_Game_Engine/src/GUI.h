#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Engine {
	class GUI
	{
	public:
		GUI(sf::RenderWindow* window);
		~GUI();
	public:
		bool isHovered(sf::RectangleShape& button);
		bool isClicked(sf::RectangleShape& button, float delayTime);
		void SetPointer(sf::RectangleShape& pointer, bool hideMouse);
	private:
		sf::RenderWindow& m_window;
		sf::Clock m_clock;
		sf::Time m_delayTime;
	};
}