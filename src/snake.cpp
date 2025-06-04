#include "snake.h"

Snake::Snake() {
	bool turn = false;
	turnPos = startPos;
	moveDirection = Direction::Right;

	body.push_back(createSegment(true, true));


	grow();
	grow();
	grow();
	grow();
}

Snake::~Snake() {
}

void Snake::grow() {
	if (!body.empty()) {
		body.back().isTail = false;
	}

	body.push_back(createSegment(false, true));
}


void Snake::updateSnake() {
	for (auto& segment : body) {
		moveSegments(segment, segment.segDirection);
	}
}

void Snake::changeDirection(Direction newDirection) {
	for (int i = 0; i < body.size(); ++i) {
		body[i].segDirection = newDirection;
		for (int j = 0; j < body.size(); ++j) {
		    moveSegments(body[j], body[j].segDirection);
		}
	}
}



void Snake::renderSnake(sf::RenderTarget& target) {
	for (const auto& segment : body) {
		target.draw(segment.part);
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
		segment.part.setPosition({ getTailPos().x - segmentSize, getTailPos().y });
	}

	segment.segDirection = Direction::Right;
	segment.isHead = isHead;
	segment.isTail = isTail;
	return segment;
}

void Snake::moveSegments(SnakeSegment& segment, Direction direction) {

	switch (direction) {
	case Direction::Up:
		segment.part.move({ 0.f, -segmentSize });
		break;

	case Direction::Down:
		segment.part.move({ 0.f, segmentSize });
		break;

	case Direction::Left:
		segment.part.move({ -segmentSize, 0.f });
		break;

	case Direction::Right:
		segment.part.move({ segmentSize, 0.f });
		break;
	}

}