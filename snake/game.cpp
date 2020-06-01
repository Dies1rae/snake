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

	sf::Text snake("*", font, 15);
	snake.setFillColor(sf::Color::Black);


	for (int ptr = 0; ptr < fieldARRAY_SIZE; ptr++) {	
		sf::Vector2f position(ptr % fieldSIZE * pxCELL_SIZE, ptr / fieldSIZE * pxCELL_SIZE);
		snake.setPosition(position.x+0.5, position.y-1);
		shape.setPosition(position);
		target.draw(shape, states);
		for (int ptr1 = 0; ptr1 < SNAKEMAIN->get_length()*2;ptr1++) {
			if (SNAKEMAIN->get_coord()[ptr1] == ptr) {
				std::cout << SNAKEMAIN->get_coord()[ptr1] << std::endl;
				target.draw(snake, states);
			}
		}
		
		

	}
}