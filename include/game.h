#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "snake.h"

class Game {
private:
	// === Window ===
	std::optional<sf::RenderWindow> window;

	// === Screen Objects
	Snake snake;
	sf::RectangleShape food;

	// === Game Logic ===
	bool gameOver;
	int score;

	// === Initalization Functions ==
	void initVariables();
	void initWindow();



public:
	// === Constructors / Destructor ===
	Game();
	~Game();

	// === Accessors ===
	const bool isWindowOpen();

	// === Game Control ===
	void runGame();

	// === Update Functions ===
	void updateEvent();

	// === Render Functions === 
	void render();
}