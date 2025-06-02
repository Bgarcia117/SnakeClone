#include "snake.h"

Snake::Snake() {
	moveDirection = Direction::Right;
	grow();
}

Snake::~Snake() {
}

void Snake::grow() {
	sf::RectangleShape bodySegment;
	bodySegment.setSize({ segmentSize, segmentSize }); 
	bodySegment.setFillColor(sf::Color::Green);

	if (body.empty()) {
		bodySegment.setPosition({ 200.f, 200.f });
	}

	body.push_back(bodySegment);
}

void Snake::move(sf::Vector2u windowSize) {
	switch (moveDirection) {
	case Direction::Up:
		break;

	case Direction::Down:
		break;

	case Direction::Left:
		break;

	case Direction::Right:
		if (body[0].getPosition().x + segmentSize < windowSize.x)
		    body[0].move({ segmentSize, 0.f });

		break;
	}

}


void Snake::renderSnake(sf::RenderTarget& target) {
	for (const auto& segment : body) {
		target.draw(segment);
	}
}