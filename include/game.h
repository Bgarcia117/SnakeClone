#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

	// === Window Objects ===
	Snake snake;
	sf::RectangleShape food;

	// === Game Logic ===
	sf::Clock moveClock;
	const float moveInterval = 0.15f; // Moves every 0.15 sec for movesa
	bool gameOver;
	int score;

	// === Initalization Functions ==
	void initVariables();
	void initWindow();



}; 