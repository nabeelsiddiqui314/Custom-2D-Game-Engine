#include "stdafx.h"
#include "RangeChecker.h"

namespace Engine {
	RangeChecker::RangeChecker()
	{
	}

	float RangeChecker::CheckDistance(sf::RectangleShape& rect1, sf::RectangleShape& rect2) {
		float xDifference = abs((rect1.getPosition().x + rect1.getGlobalBounds().width / 2)
			- (rect2.getPosition().x + rect2.getGlobalBounds().width / 2));
		float yDifference = abs((rect1.getPosition().y + rect1.getGlobalBounds().height / 2)
			- (rect2.getPosition().y + rect2.getGlobalBounds().height / 2));

		float distance = sqrt(pow(xDifference, 2) + pow(yDifference, 2));

		return distance;
	}

	bool RangeChecker::isInRange(sf::RectangleShape& rect1, sf::RectangleShape& rect2, float radius) {
		if (CheckDistance(rect1, rect2) < radius)
			return true;
		else
			return false;
	}

	RangeChecker::~RangeChecker()
	{
	}
}