#pragma once
#include <iostream>
#include <vector>
#include "snake_part.h"

class snake{
private:
	int snake_length;
	char way;
	std::vector <snake_part> body;
public:
	snake() {
		this->snake_length = 3;
		this->way = 'r';
		for (auto ptr = this->snake_length; ptr > 0; ptr--) {
			body[this->snake_length - ptr].set_state_snake_part(1);
			body[this->snake_length - ptr].set_coord_snake_part(0, ptr);
		}
	}
	snake(int LEN, int HX, int HY): snake_length(LEN), way('r'){
		this->body[0].set_coord_snake_part(HX, HY);
		for (auto ptr = LEN - 1; ptr > 0; ptr--) {
			body[LEN - ptr].set_state_snake_part(1);
			body[LEN - ptr].set_coord_snake_part(HX, HY-1);
		}
	}
	~snake() {};

	void snake_moove();
	void snake_set_way(char w);
	void snake_eat(bool eat);
};

