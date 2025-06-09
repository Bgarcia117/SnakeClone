#pragma once

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

	// === Constructors / Destructor
	Snake();
	~Snake();

	// === Accessors ===
	Direction getDirection() const { return moveDirection; }
	void setDirection(Direction newDirection) { moveDirection = newDirection; }
	sf::Vector2i getHeadPos() const { 
		sf::Vector2f po s = body.front().part.getPosition();
		return sf::Vector2i(static_cast<int> (pos.x), static_cast<int>(pos.y));
	}
	sf::Vector2i getTailPos() const { return body.back().part.getPosition(); }

	// === Transformers ===
	void grow();
	void changeDirection(Direction newDirection);
	void updateSnake();

	// Rendering
	void renderSnake(sf::RenderTarget& target) const;

private:
	// === Constants ===
	const int segmentSize = 20;
	const sf::Vector2i startPos = { 200, 200 };

	// === Variables ===
	Direction moveDirection;
	Direction nextDirection;

	// === Snake Body ===
	std::vector<SnakeSegment> body;
	SnakeSegment createSegment(bool isHead = false, bool isTail = false) const;
	void moveSegments(SnakeSegment& segment, Direction direction);


};