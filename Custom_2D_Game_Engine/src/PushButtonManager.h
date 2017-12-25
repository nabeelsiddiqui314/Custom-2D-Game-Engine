#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "PushButton.h"
#include <unordered_map>

namespace Engine {
	class PushButtonManager
	{
	public:
		PushButtonManager(const Type& type);
		~PushButtonManager();
	public:
		void Add(std::string name, const sf::Vector2f& size, const sf::Vector2f& pos, const std::string filepath, const sf::IntRect& crop,
			const sf::IntRect&  hovered, const sf::IntRect&  clicked);
		void Update(sf::RenderWindow& window);
		const PushButton& Get(const std::string name) const;
		void DeselectAll();
	private:
		Type                                         m_type;
		std::unordered_map <std::string, PushButton> m_buttonGroup;
		PushButton                                   m_pb;
		PushButton*                                  m_clickedWidget = nullptr;
	};
}