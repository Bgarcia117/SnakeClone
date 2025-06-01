#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Snake {
private:
	// Snake Body
	std::vector<sf::RectangleShape> body;


public:
	// === Constructors / Destructor
	Snake();
	~Snake();

	void grow();
	void updatePositon();
	void renderSnake(sf::RenderTarget& target);
};