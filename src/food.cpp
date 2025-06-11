#include "food.h"

Food::Food() : food() {
	food.setSize({static_cast<float>(foodSize.x), static_cast<float>(foodSize.y)});
	food.setFillColor(sf::Color::Red);
	food.setPosition({ static_cast<float>(foodStartPos.x), 
		               static_cast<float>(foodStartPos.y) });
}

Food::~Food() {

}

void Food::renderFood(sf::RenderTarget& target) const {
	target.draw(food);
}

void Food::setPosition(sf::Vector2f newPositon) {

}

void Food::spawnFood(const Snake& snake) {
	int x;
	int y;
}
