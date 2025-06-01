#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "snake.h"

int main() {
    
    Game game; // Init Game

    while (game.isWindowOpen())
    {
        game.updateEvent();

    }


	return 0;
}