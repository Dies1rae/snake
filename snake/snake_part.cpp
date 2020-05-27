#include "snake_part.h"
#include <iostream>
#include <vector>
void snake_part::set_coord_snake_part(int x, int y) {
	this->coord.clear();
	this->coord.push_back(x);
	this->coord.push_back(y);
}
void snake_part::set_coord_snake_part(std::vector <int> XY) {
	this->coord.clear();
	this->coord = XY;
}
void snake_part::set_state_snake_part(bool c) {
	this->state = c;
}
std::vector<int> snake_part::get_coord_snake_part() {
	return this->coord;
}
bool snake_part::get_state_snake_part() {
	return this->state;
}