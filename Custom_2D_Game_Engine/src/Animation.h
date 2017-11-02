#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Engine {
	class Animation
	{
	public:
		Animation();
		~Animation();
	public:
		void Animate(sf::RectangleShape& rect, sf::Vector2i size, sf::Vector2i startCoords[], int arraySize, float deltaTime);
	private:
		sf::Clock m_animationClock;
		sf::Time m_animationTIme;
		int m_index = 0;
	};
}