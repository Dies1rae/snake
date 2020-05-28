#pragma once
#include <iostream>
class snake_part{
private:
	bool state;
	int x;
	int y;
	class snake_part* next;
public:
	snake_part() {
		this->state = 1;
		this->x = 0;
		this->y = 0;
		this->next = NULL;
	}
	snake_part(int X, int Y ) : state(1), x(X), y(Y), next(NULL) {}
	~snake_part() {
		if (this->next != NULL) {
			delete this->next;
		}
	};

	void move(int X, int Y, bool G);
	int* get_SP_coord();
	void set_SP_coord(int X, int Y);
	bool get_SP_state();
	void set_SP_state(bool S);
};

