#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Interface.h"

namespace Engine {

	enum Type {
		SELECT,
		INFINITE
	};

	class PushButton : public sf::RectangleShape
	{
	public:
		 PushButton();
		~PushButton();
	public:
		void Init(const sf::Vector2f& size, const sf::Vector2f& pos, const std::string filepath, const sf::IntRect& crop,
			const  sf::IntRect&  hovered, const sf::IntRect& clicked, const Type& type);

		void CropWidget(sf::RenderWindow& window);
		void Deselect() { m_clicked = false; }

		bool IsClicked() const { return m_clicked; }
		bool IsHovered() const { return m_hovered; }
	private:
		sf::Texture m_icon;
		sf::Clock   m_clock;
		sf::Time    m_delaytime;
		Type        m_type;

		sf::IntRect m_clickRect,
			        m_hoverRect,
			        m_originalRect;
		bool        m_clicked,
			        m_hovered;
	};
}