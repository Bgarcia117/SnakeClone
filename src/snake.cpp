#include "snake.h"

Snake::Snake() {
	grow();
}

Snake::~Snake() {
}

void Snake::grow() {
	sf::RectangleShape bodySegment;
	bodySegment.setSize({ 20.f, 20.f });
	body.push_back(bodySegment);
}

void Snake::updatePositon() {

}


void Snake::renderSnake(sf::RenderTarget& target) {
	target.draw(body[0]);
}