#pragma once
#include "SFML/Graphics.hpp"

//base sizes in const int
const int fieldSIZE = 65;							//array H && W
const int fieldARRAY_SIZE = fieldSIZE * fieldSIZE;	//array 
const int pxFIELD_SIZE = 600;						//array in pixels
const int pxCELL_SIZE = 10;							//one elem of array in pixels

const sf::Color FillCell(0xDB, 0x70, 0x93);
const sf::Color OutLine(0xFF, 0x63, 0x47);
const sf::Color GameField(0x00, 0x80, 0x80);
const sf::Color DarkGray(0xA9, 0xA9, 0xA9);
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

