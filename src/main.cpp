/**
 * @brief Entry point of the Snake game
 * 
 * Initalizes the Game object and starts the main game loop.
 * The loop continues running the game while the window is open and the 
 * gameOver flag is not set.
 * 
 * Handles:
 * - Event processing
 * - Game state updates
 * - Rendering frames
 * 
 * @return int Exit status code
 */

#include <iostream>

#include "game.h"
#include "snake.h"

int main() {
    
    Game game; // Init Game

    while (game.isWindowOpen() && !game.isGameOver()) {
        game.updateEvent();
        game.updateGameState();
        game.render();
    }

	return 0;
}