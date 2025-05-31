#pragma once

#include <SFML/Graphics.hpp>
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
};