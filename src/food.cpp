#include "food.h"

Food::Food() : food() {
	food.setSize(foodSize);
	food.setFillColor(sf::Color::Red);
	food.setPosition(foodStartPos);
}

Food::~Food() {

}

void Food::renderFood(sf::RenderTarget& target) const {
	target.draw(food);
}

void Food::setPosition() {

}


