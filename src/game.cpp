#include "game.h"

Game::Game() : snake() {
	initVariables();
	initWindow();
	render();
	
}

Game::~Game()
{
}

bool Game::isWindowOpen() const {
	return window->isOpen();
}


void Game::updateEvent() {
	// check all the window's events that were triggered since the last iteration of the loop
	while (const std::optional event = window->pollEvent()) {

		// "close requested" event: we close the window
		if (event->is<sf::Event::Closed>()) {
			window->close();
		}
		// getIf returns a pointer
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

			switch (keyPressed->scancode) {
				case sf::Keyboard::Scancode::W:
				case sf::Keyboard::Scancode::Up:
					snake.moveSnake(Snake::Direction::Up);
					break;

				case sf::Keyboard::Scancode::S:
				case sf::Keyboard::Scancode::Down:
					snake.moveSnake(Snake::Direction::Down);
					break;

				case sf::Keyboard::Scancode::A:
				case sf::Keyboard::Scancode::Left:
					snake.moveSnake(Snake::Direction::Left);
					break;

				case sf::Keyboard::Scancode::D:
				case sf::Keyboard::Scancode::Right:
					snake.moveSnake(Snake::Direction::Right);
					break;
			}

		}

	}
}

void Game::updateGameState() {
	// Check if enough time has passed to make a move and move snake
	if (moveClock.getElapsedTime().asSeconds() >= moveInterval) {
	    snake.move(snake.getDirection());
		moveClock.restart();
	}
}

void Game::render() {
	window->clear();

	// Error Handling for optional window & dereferences
	if (window) snake.renderSnake(*window);

	window->display();
}

void Game::initVariables() {
	gameOver = false;
	score = 0;

	food.setPosition({ 50.f, 50.f });
	food.setSize({ 10.f, 10.f });
}

void Game::initWindow() {
	window.emplace(
		sf::VideoMode({600, 600}),
		"Snake",
		sf::Style::Default  // Includes windowed, titlebar, and resize
	);

	window->setFramerateLimit(60);
}