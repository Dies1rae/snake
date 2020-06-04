#pragma once
#include "SFML/Graphics.hpp"
#include "snake.h"
#include "apple.h"

//base sizes in const int
const int fieldSIZE = 65;							//array H && W
const int pxCELL_SIZE = 10;							// 1 cell size
//colors
extern sf::Color FillCell;
extern sf::Color OutLine;
extern sf::Color GameField;
extern sf::Color DarkGray;
extern sf::Color TEXTS;
//snake move parametrs and speed
extern int move;
extern bool appleGOT;
//APPLE
extern apple MAINAPPLE;
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
