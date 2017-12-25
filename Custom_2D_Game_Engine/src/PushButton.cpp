#include "stdafx.h"
#include "PushButton.h"

namespace Engine {
	PushButton::PushButton()
	{
	}


	void PushButton::Init(const sf::Vector2f& size, const sf::Vector2f& pos, const std::string filepath, const sf::IntRect& crop,
		const  sf::IntRect&  hovered, const sf::IntRect& clicked, const Type& type) {
		m_type = type;
		m_clickRect = clicked;
		m_hoverRect = hovered;
		m_originalRect = crop;

		this->setSize(size);
		this->setPosition(pos);

		m_icon.loadFromFile("./assets/widgets/" + filepath);
		this->setTexture(&m_icon);
		this->setTextureRect(crop);
	}

	void PushButton::CropWidget(sf::RenderWindow& window) {
		switch (m_type) {
		case SELECT:
			if (Interface::isClicked(window, *this)) {
				m_clicked = true;
				this->setTextureRect(m_clickRect);
			}
			break;
		case INFINITE:
			if (Interface::isClicked(window, *this)) {
				m_clicked = true;
				this->setTextureRect(m_clickRect);
			}
			else m_clicked = false;
			break;
		}

		if (m_clicked || !Interface::isHovered(window, *this)) {
			m_hovered = false;
		}
		if (Interface::isHovered(window, *this) && !m_clicked) {
			m_hovered = true;
		}
		if (m_hovered && !m_clicked) this->setTextureRect(m_hoverRect);
		else if (!m_hovered && !m_clicked) this->setTextureRect(m_originalRect);
	}



	PushButton::~PushButton()
	{
	}
}