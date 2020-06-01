#pragma once
#include <iostream>
#include "snake_part.h"
#define grow true
class snake{
private:
	int way;
	int length;
	snake_part* body;
public:
	snake() {
		this->way = 0;
		this->length = 3;
		this->body = new snake_part(5, 5);
		for (int ptr = 1; ptr < this->length; ptr++) {
			this->body->move(5, 5 + ptr, grow);
		}
	}
	~snake(){
		delete this->body;
	}
	void move_to_direction_grow(int W, bool G);
	int get_length();
	int get_way();
	int* get_coord();
};

