#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace Engine {
	class State
	{
	public:
		State          () {}
		virtual ~State () {}
	public:
		virtual void Init        (sf::RenderWindow& window) = 0;
		virtual void HandleInput (sf::RenderWindow& window) = 0;
		virtual void Update      (sf::RenderWindow& window) = 0;
		virtual void Render      (sf::RenderWindow& window) = 0;
		virtual void Destroy     (sf::RenderWindow& window) = 0;
	};
}