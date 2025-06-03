#include <iostream>

#include "game.h"
#include "snake.h"

int main() {
    
    Game game; // Init Game

    while (game.isWindowOpen()) {
        game.updateEvent();
        game.updateGameState();
        game.render();
    }


	return 0;
}