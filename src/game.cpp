/**
 * @file game.cpp
 * @brief Implementation of Game class
 * 
 * This files contains the implementation of all the Game class methods.
 * The Game class controls and coordinates the game components
 */

#include "game.h"

/**
 * @brief Default constructor
 * 
 * Intializes the game with:
 * - Creates and configures the game window
 * - Intializes snake and food objects
 * - Sets up random number generator for food placement
 * resets game state variables
 */
Game::Game() : snake(), food(), gameOver(false), score(0), gen(rd()), 
               screenSize(0, 29) {

	initWindow();
}

Game::~Game() {
	// SFML objects clean themselves up automatically
}

/**
 * @brief Check if the game window is still open
 * @return true if the window is open, false otherwise
 */
bool Game::isWindowOpen() const {
	return window->isOpen();
}

/**
 * @brief Check if a win/lose condition has been met
 * 
 * Game ends if:
 * - Snake reaches its maximum length (wins)
 * - Snake collides with screen edge or itself (lose)
 * 
 * @return true if the game is over, false otherwises
 */
bool Game::isGameOver() const {
	// Check if snake has reached maximum length
	if (snake.isMaxLength()) {
		std::cout << "YOU WIN!" << std::endl;
		return true;
	}

	// Check if game over flag has been set
	if (gameOver) {
		std::cout << "YOU LOSE!   \nGAME OVER!" << std::endl;
		return true;
	}

	return gameOver;
}

/**
 * @brief Process window and input events
 * 
 * Handles:
 * - Window close events
 * - Keyboard input for snake direction changes
 * - Other SFML window events
 */
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
					snake.changeDirection(Direction::Up);
					break;

				case sf::Keyboard::Scancode::S:
				case sf::Keyboard::Scancode::Down:
					snake.changeDirection(Direction::Down);
					break;

				case sf::Keyboard::Scancode::A:
				case sf::Keyboard::Scancode::Left:
					snake.changeDirection(Direction::Left);
					break;

				case sf::Keyboard::Scancode::D:
				case sf::Keyboard::Scancode::Right:
					snake.changeDirection(Direction::Right);
					break;
			}

		}

	}
}

void Game::updateGameState() {
	// Check if enough time has passed to make a move and move snake
	if (moveClock.getElapsedTime().asSeconds() >= moveInterval) {
		snake.updateSnake();
		snakeOutOfBounds();
		snakeSelfCollision();
		updateFoodPos();
		moveClock.restart();
	}
}

void Game::render() {
	window->clear();

	// Error Handling for optional window & dereferences
	if (window) {
		food.renderFood(*window);
		snake.renderSnake(*window);
	}

	window->display();
}

void Game::initWindow() {
	window.emplace(
		sf::VideoMode({ windowSize.x, windowSize.y }),
		"Snake",
		sf::Style::Default  // Includes windowed, titlebar, and resize
	);

	window->setFramerateLimit(60);
}

void Game::snakeOutOfBounds() {
	sf::Vector2i snakePos = snake.getHeadPos();

	if (snakePos.x < 0 || snakePos.x >= static_cast<int>(windowSize.x) ||
		snakePos.y < 0 || snakePos.y >= static_cast<int>(windowSize.y)) {
		gameOver = true;
	}
}

void Game::snakeSelfCollision() {
	std::vector<sf::Vector2f> positions = snake.getSegmentPos();
	sf::Vector2f head = positions[0];

	for (size_t i = 1; i < positions.size(); ++i) {
		if (positions[i] == head) {
			gameOver = true;
		}
	}
}

void Game::updateFoodPos() {
	std::vector<sf::Vector2f> positions = snake.getSegmentPos();
	sf::Vector2f foodPos = food.getFoodPos();

	if (std::find(positions.begin(), positions.end(), foodPos) != positions.end()) {

		while(std::find(positions.begin(), positions.end(), foodPos) != positions.end()) {
			int newX = screenSize(gen) * 20;
			int newY = screenSize(gen) * 20;
			food.moveFood({ newX, newY });
	
			foodPos = food.getFoodPos();
		}

		snake.grow();
	}

}

  