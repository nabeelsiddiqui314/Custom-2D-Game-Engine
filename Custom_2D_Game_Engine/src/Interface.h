#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Engine {
	class Interface
	{
	public:
		Interface();
		~Interface();
	public:
		static bool isHovered (sf::RenderWindow& window, sf::RectangleShape& button);
		static void SetPointer(sf::RenderWindow& window, sf::RectangleShape& pointer, bool hideMouse);
		static bool isClicked (sf::RenderWindow& window, sf::RectangleShape& button);
	};
}