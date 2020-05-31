#pragma once
#include "SFML/Graphics.hpp"

//base sizes in const int
const int fieldSIZE = 4;							//array H && W
const int fieldARRAY_SIZE = fieldSIZE * fieldSIZE;	//array 
const int pxFIELD_SIZE = 500;						//array in pixels
const int pxCELL_SIZE = 120;							//one elem of array in pixels
//ways
enum class Direction {
	left = 2,
	right = 3,
	up = 1,
	down = 4
};

/* move patterns
	1
2	0	3
	4

	u
l	C	r
	d

*/
class game:public sf::Drawable, public sf::Transformable{
protected:
	int elements[fieldARRAY_SIZE];
	sf::Font font;
public:
	game() {
		font.loadFromFile(".//fonts//AGENCYB.TTF");
		Init();
	};
	~game(){}

	void Init();
	void Move(Direction direction);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

