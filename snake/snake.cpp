#include "snake.h"
#include <iostream>
#include "snake_part.h"


void snake::move_to_direction_grow(int W, bool G) {
	if (G) {
		this->length++;
	}
	this->way = W;
	if (W == 1) {
		this->body->move(this->body->get_SP_coord()[0] - 1, this->body->get_SP_coord()[1], G);
	}
	if (W == 4) {
		this->body->move(this->body->get_SP_coord()[0] + 1, this->body->get_SP_coord()[1], G);
	}
	if (W == 2) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] - 1, G);
	}
	if (W == 3) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] + 1, G);
	}
}
int snake::get_length() {
	return this->length;
}
int snake::get_way() {
	return this->way;
}
int* snake::get_coord() {
	int* coord = new int;
	coord = (int*)malloc((this->length*2) * sizeof(int));
	snake_part* tmp = this->body;
	int i = 0;
	while (tmp) {
		coord[i] = tmp->get_SP_coord()[0];
		coord[i+1] = tmp->get_SP_coord()[1];
		i += 2;
		tmp = tmp->next;
	}
	return coord;
}


	/* move patterns
		1
	2	0	3
		4
	
		u
	l	C	r
		d
	
	*/
