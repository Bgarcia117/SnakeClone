#include "snake.h"

Snake::Snake() {
	grow();
}

Snake::~Snake() {
}

void Snake::grow() {
	sf::RectangleShape bodySegment;
	bodySegment.setSize({ 100.f, 100.f });
	body.push_back(bodySegment);
}

