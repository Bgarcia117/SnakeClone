#pragma once

#include <vector>

class Snake {
private:
	// Snake Body
	std::vector<sf::RectangleShape>;


public:
	// === Constructors / Destructor
	Snake();
	~Snake();

	void grow();
};