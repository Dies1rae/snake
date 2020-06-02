#pragma once
#include "SFML/Graphics.hpp"
#include "snake.h"

//base sizes in const int
const int fieldSIZE = 65;							//array H && W
const int pxCELL_SIZE = 10;
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
	int elements[fieldSIZE][fieldSIZE];
	sf::Font font;
	
public:
	snake* SNAKEMAIN;
	game() {
		this->SNAKEMAIN = new snake();
		font.loadFromFile(".//fonts//AGENCYB.TTF");
		Init();
	};
	~game(){
		this->SNAKEMAIN->~snake();
	}
	void Init();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

