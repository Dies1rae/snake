#pragma once
#include <iostream>
#include <vector>
class snake_part{
private:
	bool state;
	std::vector <int> coord;
public:
	snake_part() {
		this->state = 1;
		this->coord = {0,0};
	}
	snake_part(std::vector<int> XY) : state(1), coord(XY) {}
	snake_part(int x, int y) {
		this->state = 1;
		this->coord.push_back(x);
		this->coord.push_back(y);
	}
	~snake_part() {};

	void set_coord_snake_part(int x, int y);
	void set_coord_snake_part(std::vector <int> XY);
	void set_state_snake_part(bool c);
	std::vector<int> get_coord_snake_part();
	bool get_state_snake_part();
	
};

