#include "game.h"

void game::Init() {
	for (int ptr = 0; ptr < fieldSIZE-1; ptr++) {
		elements[ptr] = 0;
	}
}

void game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);

	sf::RectangleShape shape(sf::Vector2f(fieldSIZE, fieldSIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	shape.setSize(sf::Vector2f(pxCELL_SIZE - 2, pxCELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	sf::Text text("", font, 50);

	for (int ptr = 0; ptr < fieldARRAY_SIZE; ptr++) {
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[ptr]));
		if (elements[ptr] == 0) {
			sf::Vector2f position(ptr % fieldSIZE * pxCELL_SIZE + 10.f, ptr / fieldSIZE * pxCELL_SIZE + 10.f);
			shape.setPosition(position);
			text.setPosition(position.x + 30.f + (elements[ptr] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}