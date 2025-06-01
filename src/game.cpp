#include "game.h"

void Game::initVariables() {
	gameOver = false;
	score = 0;
}

void Game::initWindow() {
	window.emplace(
		sf::VideoMode( {800, 600} ),
		"Snake",
		sf::Style::Default  // Includes windowed, titlebar, and resize
	);

	window->setFramerateLimit(60);
}


Game::Game() {
	initVariables();
	initWindow();
	Snake();
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



