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
	void storeTurnPos(sf::Vector2f newPos) { turnPos = getHeadPos(); }
	sf::Vector2f getHeadPos() const { return body.front().part.getPosition(); }
	sf::Vector2f getTailPos() const { return body.back().part.getPosition(); }

	// === Transformers ===
	void grow();
	void changeDirection(Direction newDirection);
	void updateSnake();

	// Rendering
	void renderSnake(sf::RenderTarget& target);




	 
private:
	// === Constants ===
	const float segmentSize = 20.f;
	const sf::Vector2f startPos = { 200.f, 200.f };

	// === Variables ===
	bool turn;
	sf::Vector2f turnPos;
	Direction moveDirection;

	// === Snake Body ===
	std::vector<SnakeSegment> body;
	SnakeSegment createSegment(bool isHead = false, bool isTail = false);
	void moveSegments(SnakeSegment& segment, Direction direction);


};