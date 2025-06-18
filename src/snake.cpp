/**
 * @brief Move a segment in the specified direction
 * 
 * Updates the position of a single segment based on the movement direction
 * Handles the coordinates
 * @file snake.cpp
 * @brief Implementation of the Snake class
 * 
 * This file containns the implementation of all Snake class methods
 * The Snake class amanges the player-controlled snake including movement,
 * growth, direction changes, and render each segment.


*/

#include "snake.h"

/**
 * @brief Default constructor
 * 
 * Initializes the snake with:
 * - Starting position at (200, 200)
 * - Initial length of 3 segments
 * - Default movement direction (Right)
 * - Head, body, and tail segments configured
 */
Snake::Snake() : length(1), moveDirection(Direction::Right), 
                            nextDirection(Direction::Right) {

	body.push_back(createSegment(true, true));

	grow();
	grow();
}

Snake::~Snake() {
}

sf::Vector2i Snake::getHeadPos() const {
	sf::Vector2f pos = body.front().part.getPosition();
	return { static_cast<int>(pos.x), static_cast<int>(pos.y) };
}

sf::Vector2i Snake::getTailPos() const {
	sf::Vector2f pos = body.back().part.getPosition();
	return { static_cast<int>(pos.x), static_cast<int>(pos.y) };
}

std::vector<sf::Vector2f> Snake::getSegmentPos() const {
	std::vector<sf::Vector2f> positions;

	for (const auto& segment : body) {
		positions.push_back(segment.part.getPosition());
	}

	return positions;
}

bool Snake::isMaxLength() const {
	return length == 30;
}

void Snake::grow() {
	if (!body.empty()) {
		body.back().isTail = false;
	}

	body.push_back(createSegment(false, true));
	length++;
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

void Snake::renderSnake(sf::RenderTarget& target) const {
	for (const auto& segment : body) {
		target.draw(segment.part);
	}
}

SnakeSegment Snake::createSegment(bool isHead, bool isTail) const {
	SnakeSegment segment;
	segment.part.setSize({ static_cast<float>(segmentSize), 
		                   static_cast<float>(segmentSize) });
	segment.part.setFillColor(isHead ? sf::Color::Yellow : sf::Color::Green);
	segment.part.setOutlineColor(sf::Color::Black);
	segment.part.setOutlineThickness(1);

	if (body.empty()) {
		segment.part.setPosition({static_cast<float>(startPos.x), 
			                      static_cast<float>(startPos.x)});

	}
	else {
		segment.part.setPosition({ static_cast<float>(getTailPos().x - segmentSize), 
			                       static_cast<float>(getTailPos().y) });
	}

	segment.segDirection = Direction::Right;
	segment.isHead = isHead;
	segment.isTail = isTail;
	return segment;
}

void Snake::moveSegments(SnakeSegment& segment, Direction direction) {

	switch (direction) {
	case Direction::Up:
		segment.part.move({ 0, static_cast<float>(-segmentSize)});
		break;

	case Direction::Down:
		segment.part.move({ 0, static_cast<float>(segmentSize) });
		break;

	case Direction::Left:
		segment.part.move({ static_cast<float>(-segmentSize), 0 });
		break;

	case Direction::Right:
		segment.part.move({ static_cast<float>(segmentSize), 0 });
		break;
	}
}