#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "snake.h"

class Game {
private:
	// === Window ===
	std::optional<sf::RenderWindow> window;
	Snake snake;
	
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

	// Update Functions
	void updateEvent();

};