#pragma once
#include <iostream>
class snake_part{
private:
	bool state;
	int x;
	int y;
public:
	class snake_part* next;
	snake_part() {
		this->state = 1;
		this->x = 0;
		this->y = 0;
		this->next = NULL;
	}
	snake_part(int X, int Y){
		this->state = 1;
		this->x = X;
		this->y = Y;
		this->next = NULL;
	}
	~snake_part() {
		if (this->next != NULL) {
			delete this->next;
		}
	};

	void move(int X, int Y, bool G);
	void set_SP_coord(int X, int Y);
	bool get_SP_state();
	void set_SP_state(bool S);
	int* get_SP_coord();
};

