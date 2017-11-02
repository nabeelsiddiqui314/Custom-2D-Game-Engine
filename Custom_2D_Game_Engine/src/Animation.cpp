#include "stdafx.h"
#include "Animation.h"

namespace Engine {
	Animation::Animation() {

	}

	void Animation::Animate(sf::RectangleShape& rect, sf::Vector2i size, sf::Vector2i startCoords[], int arraySize, float deltaTime) {
		m_animationTIme = m_animationClock.getElapsedTime();

		if (m_animationTIme.asMilliseconds() > deltaTime) {
			rect.setTextureRect(sf::IntRect(startCoords[m_index], size)); // Loops through picture coordinates

			if (m_index >= arraySize - 1) { // Checks if index exceeds the array length
				m_index = 0;
			}
			else {
				m_index++;
			}
			m_animationClock.restart();
		}
	}

	Animation::~Animation() {

	}
}