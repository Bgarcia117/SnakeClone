#include "game.h"

void Game::initVariables() {
	gameOver = false;
	score = 0;

	food.setPosition({ 50.f, 50.f });
	food.setSize({ 10.f, 10.f });
}

void Game::initWindow() {
	window.emplace(
		sf::VideoMode({800, 600}),
		"Snake",
		sf::Style::Default  // Includes windowed, titlebar, and resize
	);

	window->setFramerateLimit(60);
}


Game::Game() : Snake() {
	initVariables();
	initWindow();
	render();
	
}

Game::~Game()
{
}

const bool Game::isWindowOpen() {
	return window->isOpen();
}

void Game::runGame()
{
}

void Game::updateEvent() {
	// check all the window's events that were triggered since the last iteration of the loop
	while (const std::optional event = window->pollEvent()) {
		// "close requested" event: we close the window
		if (event->is<sf::Event::Closed>()) {
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
				window->close();
			}
		}
	}
}

void Game::render() {
	
	// Error Handling for optional window & dereferences
	if (window.has_value()) snake.renderSnake(*window);
}
