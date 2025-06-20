#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

// === Enum for the snakes directions ===
enum class Direction {
	Up,
	Down,
	Left,
	Right
};

struct SnakeSegment {
	sf::RectangleShape part;
	Direction segDirection = Direction::Right;
	bool isHead = false;
	bool isTail = false;
};

class Snake {
public:

	// === Constructor ===
	Snake();

	// === Accessors ===
	Direction getDirection() const { return moveDirection; }
	void setDirection(Direction newDirection) { moveDirection = newDirection; }
	sf::Vector2i getHeadPos() const;
	sf::Vector2i getTailPos() const;
	std::vector<sf::Vector2f> getSegmentPos() const;
	bool isMaxLength() const;

	// === Transformers ===
	void grow();
	void changeDirection(Direction newDirection);
	void updateSnake();

	// Rendering
	void renderSnake(sf::RenderTarget& target) const;

private:
	// === Constants ===
	static constexpr int segmentSize = 20;
	static constexpr sf::Vector2i startPos = { 200, 200 };

	// === Direction ===
	Direction moveDirection;
	Direction nextDirection;

	// === Snake Body ===
	int length;
	std::vector<SnakeSegment> body;
	SnakeSegment createSegment(bool isHead = false, bool isTail = false) const;
	void moveSegments(SnakeSegment& segment, Direction direction);


};