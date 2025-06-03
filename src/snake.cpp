#include "snake.h"

Snake::Snake() {
	turnPos = startPos;
	moveDirection = Direction::Right;

	SnakeSegment head;
	head.part.setSize({ segmentSize, segmentSize });
	head.part.setFillColor(sf::Color::Cyan);
	head.part.setPosition(startPos);


	grow();
	grow();
}

Snake::~Snake() {
}

void Snake::grow() {
	sf::RectangleShape bodySegment;
	bodySegment.setSize({ segmentSize, segmentSize }); 
	bodySegment.setFillColor(sf::Color::Green);

	if (body.empty()) {
		bodySegment.setPosition(startPos);
	}
	else {
		bodySegment.setPosition({ tailPos.x - segmentSize, tailPos.y });
		tailPos = bodySegment.getPosition();
	}

	body.push_back(bodySegment);
}

void Snake::move(Direction direction) {
	setDirection(direction);

	switch (moveDirection) {
	case Direction::Up:
		for (auto& segment : body) {
			if (segment.getPosition() == turnPos)
			segment.move({ 0.f, -segmentSize });
		}
		break;

	case Direction::Down:
		for (auto& segment : body) {
			segment.move({ 0.f, segmentSize });
	    }
		break;

	case Direction::Left:
		for (auto& segment : body) {
			segment.move({ -segmentSize, 0.f });
		}
		break;

	case Direction::Right:
		for (auto& segment : body) {
			segment.move({ segmentSize, 0.f });
		}
	}

}

void Snake::renderSnake(sf::RenderTarget& target) {
	for (const auto& segment : body) {
		target.draw(segment);
	}
}

SnakeSegment Snake::createSegment(bool isHead, bool isTail) {
	SnakeSegment segment;
	segment.part.setSize({ segmentSize, segmentSize });
	segment.part.setFillColor(isHead ? sf::Color::Cyan : sf::Color::Green);

	if (body.empty()) {
		segment.part.setPosition(startPos);
	}
	else {

	}
}