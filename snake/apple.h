#pragma once


class apple{
private:
	int x;
	int y;
	bool alive;
public:
	apple() {
		this->x = 0;
		this->y = 0;
		this->alive = 0;
	}
	apple(int X, int Y):x(X), y(Y), alive(1){}
	~apple() {};

	bool get_apple_alive_status();
	void set_apple_alive_status(bool A);
	int* get_apple_coord();
	void set_apple_coord(int X, int Y);
};

