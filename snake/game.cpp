#include "game.h"
#include "snake.h"
#include <iostream>

extern snake* SNAKEMAIN = new snake();

void game::Init() {
	for (int ptr = 0; ptr < fieldARRAY_SIZE; ptr++) {
		elements[ptr] = 1;
	}
}

void game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	sf::RectangleShape shape(sf::Vector2f(fieldSIZE, fieldSIZE));
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(OutLine);
	shape.setFillColor(GameField);
	shape.setSize(sf::Vector2f(pxCELL_SIZE, pxCELL_SIZE));


	sf::Text snakehead("*", font, 15);
	snakehead.setFillColor(sf::Color::White);
	sf::Text snakebody("+", font,15);
	snakebody.setFillColor(sf::Color::Black);


	for (int ptr = 0; ptr < fieldARRAY_SIZE; ptr++) {	
		sf::Vector2f position(ptr % fieldSIZE * pxCELL_SIZE, ptr / fieldSIZE * pxCELL_SIZE);
		snakehead.setPosition(position.x + 0.5, position.y - 1);
		snakebody.setPosition(position.x + 0.5, position.y -5);
		shape.setPosition(position);
		target.draw(shape, states);

		for (int ptr1 = 0; ptr1 < SNAKEMAIN->get_length()*2;ptr1++) {
			if(ptr1 % 2 != 0){
				if (SNAKEMAIN->get_coord()[ptr1] == ptr) {
					if (ptr1 == 1) {
						target.draw(snakehead, states);
					}
					else {
						target.draw(snakebody, states);
					}
				}
			}
		}
		
		

	}
}