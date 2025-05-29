#pragma once

class Game {
private:
	// === Window ===
	sf::RenderWindow window;      // Main game window

	// === Game Logic ===
	bool gameOver;
	int score;

	// === Initalization Functions ==
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
	void update

};