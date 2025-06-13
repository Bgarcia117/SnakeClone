#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>         // For std::find

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "food.h"
#include "snake.h"

class Game {
public:
	// === Constructors / Destructor ===
	Game();
	~Game();

	// === Game Loop ===
	bool isWindowOpen() const;
	bool isGameOver() const;
	void updateEvent();
	void updateGameState(); 
	void render();

private:
	// === Window ===
	std::optional<sf::RenderWindow> window;
	const sf::Vector2u windowSize = { 600, 600 };
	void initWindow();

	// === Game Objects ===
	Snake snake;
	Food food;
	void snakeOutOfBounds();
	void updateFoodPos();

	// === Time Logic ===
	sf::Clock moveClock;
	const float moveInterval = 0.15f; // Moves every 0.15 sec for moves

	// === Game State ===
	bool gameOver;
	int score;

	// === Randomization ===
	std::random_device rd;                          // Seed for generator
	std::mt19937 gen;                               // Generator
	std::uniform_int_distribution<int> screenSize;  // Shapes the random number

}; 