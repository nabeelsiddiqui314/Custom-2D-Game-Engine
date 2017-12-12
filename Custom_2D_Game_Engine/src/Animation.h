#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

namespace Engine {
	class Animation
	{
	public:
		Animation();
		~Animation();
	public:
		void Animate(sf::RectangleShape& rect, sf::Vector2i size, std::vector<sf::Vector2i> startCoords, float deltaTime);
	private:
		sf::Clock m_animationClock;
		sf::Time  m_animationTIme;
		int	      m_index = 0;
	};
}