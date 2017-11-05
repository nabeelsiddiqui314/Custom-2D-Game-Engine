#include "stdafx.h"
#include "GUI.h"

namespace Engine {
	GUI::GUI(sf::RenderWindow* window) : m_window(*window) {
		
	}

	bool GUI::isHovered(sf::RectangleShape& button) const {
		sf::IntRect _button(button.getPosition().x, button.getPosition().y, button.getGlobalBounds().width, button.getGlobalBounds().height);
		if (_button.contains(sf::Mouse::getPosition(m_window))) {
			return true;
		}
		else {
			return false;
		}
	}

	void GUI::SetPointer(sf::RectangleShape& pointer, bool hideMouse) const {
		if (hideMouse) {
			m_window.setMouseCursorVisible(false);
		}
		else {
			m_window.setMouseCursorVisible(true);
		}
		pointer.setOrigin(pointer.getGlobalBounds().width / 2, pointer.getGlobalBounds().height / 2);
		sf::Vector2f mousePos(sf::Mouse::getPosition(m_window));
		pointer.setPosition(mousePos);
	}

	bool GUI::isClicked(sf::RectangleShape& button, float delayTime) const {
		m_delayTime = m_clock.getElapsedTime();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::IntRect button(button.getPosition().x, button.getPosition().y, button.getGlobalBounds().width, button.getGlobalBounds().height);
			if (button.contains(sf::Mouse::getPosition(m_window)) && m_delayTime.asMilliseconds() > delayTime) {
				m_clock.restart();
				return true;
			}
			else {
				return false;
			}
		}
	}


	GUI::~GUI()
	{
	}
}