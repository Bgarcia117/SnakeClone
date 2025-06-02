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

	// === Screen Objects
	Snake snake;
	sf::RectangleShape food;

	// === Game Logic ===
	bool gameOver;
	int score;

	// === Initalization Functions ==
	void initVariables();
	void initWindow();



};