#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Entity.h"

namespace Engine {
	class RangeChecker
	{
	public:
		 RangeChecker();
		~RangeChecker();
	public:
		float CheckDistance (sf::RectangleShape& rect1, sf::RectangleShape& rect2)               const;
		bool  isInRange     (sf::RectangleShape& rect1, sf::RectangleShape& rect2, float radius) const;
	};
}