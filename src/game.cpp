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

void Game::update()
{
}



