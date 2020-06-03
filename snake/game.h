#pragma once
#include "SFML/Graphics.hpp"
#include "snake.h"

//base sizes in const int
const int fieldSIZE = 65;							//array H && W
const int pxCELL_SIZE = 10;							// 1 cell size
//colour day
extern sf::Color FillCell;
extern sf::Color OutLine;
extern sf::Color GameField;
extern sf::Color DarkGray;
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
	~game(){}

	void Init();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


/* DARK THEME
FillCell.r = 19;
FillCell.g = 97;
FillCell.b = 112;
OutLine.r = 45;
OutLine.g = 3;
OutLine.b = 85;
GameField.r = 52;
GameField.g = 22;
GameField.b = 33;
DarkGray.r = 0;
DarkGray.g = 0;
DarkGray.b = 1;
*/