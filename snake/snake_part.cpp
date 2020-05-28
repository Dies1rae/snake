#include "snake_part.h"
#include <iostream>

void snake_part::move(int X, int Y, bool G) {
	if (this->next != NULL) {
		this->next->move(this->x, this->y, G);
		this->x = X;
		this->y = Y;
	}
	if (G) {
		this->next = new snake_part(this->x, this->y);
		this->x = X;
		this->y = Y;
	}
}
bool snake_part::get_SP_state() {
	return this->state;
}
void snake_part::set_SP_state(bool S) {
	this->state = S;
}
int * snake_part::get_SP_coord() {
	 int coord[2] = {this->x,this->y};
	 return coord;
}
void  snake_part::set_SP_coord(int X, int Y) {
	this->x = X;
	this->y = Y;
}