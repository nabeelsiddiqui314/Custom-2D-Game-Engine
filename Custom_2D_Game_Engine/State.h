#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace Engine {
	class State
	{
	public:
		State() {}
		~State() {}
	public:
		virtual void Init(sf::RenderWindow* window) {}
		virtual void HandleInput(sf::RenderWindow* window) {}
		virtual void Update(sf::RenderWindow* window) {}
		virtual void Render(sf::RenderWindow* window) {}
		virtual void Destroy(sf::RenderWindow* window) {}
	};
}