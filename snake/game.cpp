#include "game.h"
#include "snake.h"
#include <iostream>

//init for snake who;e

//------------------

void game::Init() {
	for (int ptr = 0; ptr < fieldSIZE; ptr++) {
		for (int ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
			elements[ptr][ptr1] = 1;
		}
	}
}

void game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	//outline
	sf::RectangleShape shapeOUTTER(sf::Vector2f(fieldSIZE* pxCELL_SIZE, fieldSIZE* pxCELL_SIZE));
	shapeOUTTER.setOutlineThickness(5.f);
	shapeOUTTER.setOutlineColor(sf::Color::Black);
	shapeOUTTER.setFillColor(sf::Color::Transparent);
	target.draw(shapeOUTTER, states);
	//gamefield
	sf::RectangleShape shape(sf::Vector2f(fieldSIZE, fieldSIZE));
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(OutLine);
	shape.setFillColor(GameField);
	shape.setSize(sf::Vector2f(pxCELL_SIZE, pxCELL_SIZE));
	//snake head and body
	sf::Text snakehead("*", font, 15);
	snakehead.setFillColor(sf::Color::White);
	sf::Text snakebody("+", font,15);
	snakebody.setFillColor(sf::Color::Black);
	//draw
	for (int ptr = 0; ptr < fieldSIZE; ptr++) {
		for (int ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
			//positions
			sf::Vector2f position(ptr % fieldSIZE * pxCELL_SIZE, ptr1 % fieldSIZE * pxCELL_SIZE);
			shape.setPosition(position);
			snakehead.setPosition(position.x + 0.5, position.y - 1);
			snakebody.setPosition(position.x + 0.5, position.y - 5);
			//draw field
			target.draw(shape, states);
			//draw snake parts and head
			for (int ptrs = 0; ptrs < this->SNAKEMAIN->get_length() * 2; ptrs++) {
				if ((ptrs % 2 == 0) && (this->SNAKEMAIN->get_coord()[ptrs] == ptr1 && this->SNAKEMAIN->get_coord()[ptrs + 1] == ptr)) {
					if (ptrs == 0) {
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
