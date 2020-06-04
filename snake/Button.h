#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape button;
	sf::Text text;
	int btnWidth;
	int btnHeight;

public:
	Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
		button.setSize(buttonSize);
		button.setFillColor(bgColor);

		btnWidth = (int)buttonSize.x;
		btnHeight = (int)buttonSize.y;

		text.setString(btnText);
		text.setCharacterSize(charSize);
		text.setFillColor(textColor);
	}
	~Button() {}


	void setFont(sf::Font& fonts);

	void setBackColor(sf::Color color);

	void setTextColor(sf::Color color);

	void setPosition(sf::Vector2f point);

	void drawTo(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window);

};
