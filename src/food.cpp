/**
 * @brief Constructor for the Food 
 */

#include "food.h"
/**
 * @brief Constructor for the Food class
 * 
 * Initializes the food object with:
 * - A fixed size (20x20 pixels)
 * - Red fill color
 * - Black outline
 * - Starting position at predefined coordinates
 */
Food::Food() : food() {
	// Set size of food rectangle
	food.setSize({static_cast<float>(foodSize.x), 
		          static_cast<float>(foodSize.y)});

	// Set fill and outline properties
	food.setFillColor(sf::Color::Red);
	food.setOutlineColor(sf::Color::Black);
	food.setOutlineThickness(1);

	// Set initial position on the grid
	food.setPosition({ static_cast<float>(foodStartPos.x), 
		               static_cast<float>(foodStartPos.y) });
}

/**
 * @brief Render the food to the target window
 * 
 * Draws the food rectangle shape to the provided window
 * 
 * @param target The render target to draw the food onto
 */
void Food::renderFood(sf::RenderTarget& target) const {
	target.draw(food);
}

/**
 * @brief Get the current position of the food
 * 
 * Returns the food position as a 2D floating point vector
 * 
 * @return sf::Vector2f The food's position on the screen
 */
sf::Vector2f Food::getFoodPos() const {
	return food.getPosition();
}

/**
 * @brief Move the food to a new position
 * 
 * Sets the food's position to the given grid aligned coordinates.
 * Used to move the food elsewhere once it is eaten
 * 
 * @param newPosition The new position to move the food to (in grid units)
 */
void Food::moveFood(sf::Vector2i newPosition) {
	// Convert integer grid coordinates to pixel coordinates
	food.setPosition({ static_cast<float>(newPosition.x),
					   static_cast<float>(newPosition.y)});
}


