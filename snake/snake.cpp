#include "snake.h"
#include <iostream>
#include <vector>
#include "snake_part.h"

void snake::snake_moove() {

}
void snake::snake_set_way(char W) {
	this->way = W;
}
void snake::snake_eat(bool eat) {
	snake_part addtmp = this->body[this->snake_length-1].get_coord_snake_part();
	this->body.push_back(addtmp);
	this->snake_length += 1;
	addtmp.~snake_part();
}
