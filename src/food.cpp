#include "food.h"

Food::Food() : food() {
	food.setSize({static_cast<float>(foodSize.x), 
		          static_cast<float>(foodSize.y)});
	food.setFillColor(sf::Color::Red);
	food.setOutlineColor(sf::Color::Black);
	food.setOutlineThickness(1);
	food.setPosition({ static_cast<float>(foodStartPos.x), 
		               static_cast<float>(foodStartPos.y) });
}

Food::~Food() {

}

void Food::renderFood(sf::RenderTarget& target) const {
	target.draw(food);
}

sf::Vector2f Food::getFoodPos() const {
	return food.getPosition();
}

void Food::moveFood(sf::Vector2i newPosition) {
	food.setPosition({ static_cast<float>(newPosition.x),
					   static_cast<float>(newPosition.y)});
}


