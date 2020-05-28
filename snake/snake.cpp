#include "snake.h"
#include <iostream>
#include "snake_part.h"

void snake::move_to_direction(int W) {
	if (W == 1) {
		this->body->move(this->body->get_SP_coord()[0] - 1, this->body->get_SP_coord()[1], 0);
	}
	if (W == 4) {
		this->body->move(this->body->get_SP_coord()[0] + 1, this->body->get_SP_coord()[1], 0);
	}
	if (W == 2) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] - 1, 0);
	}
	if (W == 3) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] + 1, 0);
	}
}
void snake::move_to_direction_growup(int W) {
	this->length++;
	if (W == 1) {
		this->body->move(this->body->get_SP_coord()[0] - 1, this->body->get_SP_coord()[1], 1);
	}
	if (W == 4) {
		this->body->move(this->body->get_SP_coord()[0] + 1, this->body->get_SP_coord()[1], 1);
	}
	if (W == 2) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] - 1, 1);
	}
	if (W == 3) {
		this->body->move(this->body->get_SP_coord()[0], this->body->get_SP_coord()[1] + 1, 1);
	}
}
void  snake::set_way_dir(int W, bool G) {
	if (G) {
		snake::move_to_direction_growup(W);
	}
	if (!G) {
		snake::move_to_direction(W);
	}
}
	/* move patterns
		1
	2	0	3
		4
	
		u
	l	C	r
		d
	
	*/
