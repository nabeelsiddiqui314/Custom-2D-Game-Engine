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
		bool isHovered (sf::RectangleShape& button)                  const;
		void SetPointer(sf::RectangleShape& pointer, bool hideMouse) const;
		bool isClicked (sf::RectangleShape& button, float delayTime) const;
	private:
		sf::RenderWindow&         m_window;
		mutable sf::Clock         m_clock;
		mutable sf::Time          m_delayTime;
	};
}