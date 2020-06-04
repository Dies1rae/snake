#include "game.h"
#include "snake.h"
#include <iostream>
#include "apple.h"
#include <random>

sf::Color FillCell(0xDB, 0x70, 0x93);
sf::Color OutLine(0xFF, 0x63, 0x47);
sf::Color GameField(0x00, 0x80, 0x80);
sf::Color DarkGray(0xA9, 0xA9, 0xA9);
sf::Color TEXTS(sf::Color::Black);

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
	//-----------
	//snake head and body
	sf::Text snakehead("*", font, 15);
	snakehead.setFillColor(sf::Color::White);
	sf::Text snakebody("+", font,15);
	snakebody.setFillColor(sf::Color::Black);
	//apple
	sf::Text applechk("@", font, 15);
	applechk.setFillColor(sf::Color::Red);
	//-------------
	//draw
	for (int ptr = 0; ptr < fieldSIZE; ptr++) {
		for (int ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
			//positions
			sf::Vector2f position(ptr % fieldSIZE * pxCELL_SIZE, ptr1 % fieldSIZE * pxCELL_SIZE);
			shape.setPosition(position);
			snakehead.setPosition(position.x + 0.5, position.y - 1);
			snakebody.setPosition(position.x + 0.5, position.y - 5);
			applechk.setPosition(position.x + 0.5, position.y - 5);
			//draw field
			target.draw(shape, states);
			//draw snake parts and head
			for (int ptrs = 0; ptrs < this->SNAKEMAIN->get_length() * 2; ptrs++) {
				if ((ptrs % 2 == 0) && (this->SNAKEMAIN->get_coord()[ptrs] == ptr1 && this->SNAKEMAIN->get_coord()[ptrs + 1] == ptr)) {
					if (ptrs == 0) {
						target.draw(snakehead, states);
					}
					else{
						target.draw(snakebody, states);
					}
				}
			}
			if (ptr == MAINAPPLE.get_apple_coord()[1] && ptr1 == MAINAPPLE.get_apple_coord()[0] && MAINAPPLE.get_apple_alive_status()) {
				target.draw(applechk, states);
				if (this->SNAKEMAIN->get_coord()[1] == MAINAPPLE.get_apple_coord()[1] && this->SNAKEMAIN->get_coord()[0] == MAINAPPLE.get_apple_coord()[0]) {
					appleGOT = 1;
				}
			}

		}
	}
}
