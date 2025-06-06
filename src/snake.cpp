#include "snake.h"

Snake::Snake() {
	bool turn = false;
	turnPos = startPos;
	moveDirection = Direction::Right;
	nextDirection = Direction::Right;

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
	// Each segment copies the position and direction of the one in ahead of it
	for (int i = body.size() - 1; i > 0; --i) {
		body[i].part.setPosition(body[i - 1].part.getPosition());// Copy Position
		body[i].segDirection = body[i - 1].segDirection;         // Copy Direction

	}

	// After the for loop to ensure change starts at the new frame
	moveDirection = nextDirection;
	moveSegments(body[0], moveDirection);
	body[0].segDirection = moveDirection;
}

void Snake::changeDirection(Direction newDirection) {
	if ((moveDirection == Direction::Up && newDirection == Direction::Down)    ||
		(moveDirection == Direction::Down && newDirection == Direction::Up)    ||
		(moveDirection == Direction::Right && newDirection == Direction::Left) ||
		(moveDirection == Direction::Left && newDirection == Direction::Right)) {
		return;
	}

	nextDirection = newDirection;
}



void Snake::renderSnake(sf::RenderTarget& target) const  {
	for (const auto& segment : body) {
		target.draw(segment.part);
	}
}

SnakeSegment Snake::createSegment(bool isHead, bool isTail) const {
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