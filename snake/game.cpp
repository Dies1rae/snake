#include "game.h"
#include "snake.h"
#include <iostream>

extern snake* SNAKEMAIN = new snake();

void game::Init() {
	for (int y = 0; y < fieldSIZE; y++) {
		for (int x = 0; x < fieldSIZE; x++) {
			elements[y][x] = 1;
		}
	}
}

void game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	
}