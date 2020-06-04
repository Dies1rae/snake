#include "snake.h"
#include <iostream>
#include "snake_part.h"
#include <vector>

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
	if (W == 0) {
		return;
	}
}
int snake::get_length() {
	return this->length;
}
int snake::get_way() {
	return this->way;
}
std::vector<int> snake::get_coord() {
	std::vector<int> coord;
	snake_part* tmp = this->body;
	while (tmp) {
		coord.push_back(tmp->get_SP_coord()[0]);
		coord.push_back(tmp->get_SP_coord()[1]);
		tmp = tmp->next;
	}
	return coord;
}

bool  snake::snake_dies() {
	if (get_coord()[0] < 0 || get_coord()[1] < 0 || get_coord()[0] > 64 || get_coord()[1] > 64) {
		return false;
	}
	for (int ptr = 2; ptr < this->length * 2; ptr++) {
		if (ptr % 2 == 0) {
			if (get_coord()[0] == get_coord()[ptr] && get_coord()[1] == get_coord()[ptr + 1]) {
				return false;
			}
		}
	}
	return true;
}

void snake::set_sn_speed_change(double S) {
	this->speed += S;
}
float snake::get_sn_speed() {
	return this->speed;
}
void snake::set_snake_way(int W) {
	this->way = W;
}

	/* move patterns
		1
	2	0	3
		4
	
		u
	l	C	r
		d
	
	*/
