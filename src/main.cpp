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

    std::cout << "GAME OVER LOSER" << std::endl;

	return 0;
}