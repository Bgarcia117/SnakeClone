#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class Snake {
public:
	// === Enum for the snakes directions
	enum class Direction {
		Up,
		Down, 
		Left,
		Right
	};

	// === Constructors / Destructor
	Snake();
	~Snake();

	void grow();
	void move(sf::Vector2u windowSize);
	void renderSnake(sf::RenderTarget& target);
	 
private:
	// === Constants ===
	const float segmentSize = 20.f;

	// === Variables ===
	Direction moveDirection;

	// === Snake Body ===
	std::vector<sf::RectangleShape> body;


};