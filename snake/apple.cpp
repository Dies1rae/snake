#include "apple.h"
#include <random>

bool apple::get_apple_alive_status(){
	return this->alive;
}
void apple::set_apple_alive_status(bool A) {
	this->alive = A;
}
int* apple::get_apple_coord() {
	int coord[2] = { this->x, this->y };
	return coord;
}
void apple::set_apple_coord(int X, int Y) {
	this->x = X;
	this->y = Y;
	this->alive = 1;
}