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

			// Maps keyboard input to snake directions
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


/**
 * @brief Update game state logic
 * 
 * Called once per frame to:
 * - Move snake based on time passed
 * - Check collisions (walls, self, food)
 * - Update food position if eaten
 * - Manage game timing
 */
void Game::updateGameState() {
	// Check if enough time has passed to make a move and move snake
	if (moveClock.getElapsedTime().asSeconds() >= moveInterval) {
		snake.updateSnake();

		// Collision detection
		snakeOutOfBounds();   // Checks wall collisions
		snakeSelfCollision(); // Checks self collison
		updateFoodPos();      // Check food consumption

		// Reset timer for next update
		moveClock.restart();
	}
}

/**
 * @brief Render current frame to the screen
 *
 * Draws all game objects:
 * - Clears the screen
 * - Renders food
 * - Renders snake
 * - Displays the frame
 */
void Game::render() {
	// Clears previous frame
	window->clear();

	// Error Handling: ensures window exists
	if (window) {

		// Renders the food and snake
		food.renderFood(*window);
		snake.renderSnake(*window);
	}

	// Displays the frame
	window->display();
}

/**
 * @brief Intialize and configure the game window
 * 
 * Sets up:
 * - Window size and title
 * - Sets frame rate limit
 * - Window style and properties
 */
void Game::initWindow() {
	// Creates window using emplace for optional<sf::RenderWindow>
	window.emplace(
		sf::VideoMode({ windowSize.x, windowSize.y }),
		"Snake",
		sf::Style::Default  // Includes windowed, titlebar, and resize
	);

	// Sets frame rate limit to prevent timing issues
	window->setFramerateLimit(60);
}

/**
 * @brief Check if the snake has moved outside window boundaries
 * 
 * Sets gameOver flag if snake head touches the screen edge
 * Called after each snake movement
 */
void Game::snakeOutOfBounds() {
	// Get current snake head position
	sf::Vector2i snakePos = snake.getHeadPos();

	// Check if snake has moved outside or touched window boundaries
	if (snakePos.x < 0 || snakePos.x >= static_cast<int>(windowSize.x) ||
		snakePos.y < 0 || snakePos.y >= static_cast<int>(windowSize.y)) {
		
		// Set game flag - handled in next frame
		gameOver = true;
	}
}

/**
 * @brief Check if the snake has collided with itself
 * 
 * Compares snake head position with the rest of the body segments
 * Sets gameOVer flag to true if collision ius detected
 */
void Game::snakeSelfCollision() {
	// Get positions of all snake segments
	std::vector<sf::Vector2f> positions = snake.getSegmentPos();
	
	// Head is always at the first position
	sf::Vector2f head = positions[0];

	// Check if head position matches any other body segment position
	for (size_t i = 1; i < positions.size(); ++i) {
		if (positions[i] == head) {
			gameOver = true;
		}
	}
}

/**
 * @brief Handle food consumption and repositioning
 * 
 * Check if snake head overlaps with food position
 * If so:
 * - Grows the snake
 * - Moves the food to random position (avoiding snake body)
 */
void Game::updateFoodPos() {
	// Get snake segment positions for collision checking
	std::vector<sf::Vector2f> positions = snake.getSegmentPos();
	sf::Vector2f foodPos = food.getFoodPos();

	// Checks if any snake segment overlaps with the food position
	if (std::find(positions.begin(), positions.end(), foodPos) != positions.end()) {

		// Food has been consumed - find new valid position
		// Continue generating new positions until one doesn't overlap with snake
		while(std::find(positions.begin(), positions.end(), foodPos) != positions.end()) {

			// Generate random grid coordinates (0-29) and converts to pixel coordinates
			// Multiply by 20 to align with the 20x20 pixel grid size
			int newX = screenSize(gen) * 20;
			int newY = screenSize(gen) * 20;

			// Move food to the new position
			food.moveFood({ newX, newY });
	
			// Update foodPos for next iteration check
			foodPos = food.getFoodPos();
		}

		// Snake consumed the food - grow by one segment
		snake.grow();
	}

}

  