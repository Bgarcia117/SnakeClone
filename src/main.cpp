#include <iostream>

#include "game.h"
#include "snake.h"

int main() {
    
    Game game; // Init Game

    while (game.isWindowOpen()) {
        game.updateEvent();
        game.render();
    }


	return 0;
}