#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "food.h"
#include "snake.h"

class Game {
public:
	// === Constructors / Destructor ===
	Game();
	~Game();

	// === Accessors ===
	bool isWindowOpen() const;

	// === Update Functions ===
	void updateEvent();
	void updateGameState();

	// === Render Functions === 
	void render();

private:
	// === Window ===
	std::optional<sf::RenderWindow> window;
	// const sf::Vector2i windowSize = {}
	void initWindow();

	// === Window Objects ===
	Snake snake;
	Food food;

	// === Game Logic ===
	sf::Clock moveClock;
	const float moveInterval = 0.15f; // Moves every 0.15 sec for movesa
	bool gameOver;
	int score;

	// === Random Number ===
	/*std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<int>
	*/



}; 