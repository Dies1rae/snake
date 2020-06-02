#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "game.h"

int main_win_gui();
int new_game_started();
int OPTIONS();
int ABOUT();
bool snake_matters(int x, int y);

int main_win_gui() {
	
	//main window menu options
	sf::RenderWindow mainwindow(sf::VideoMode(1024, 768), "SNAKE");
	
	//icon
	sf::Image icon;
	icon.loadFromFile(".//img//icon.png");
	mainwindow.setIcon(32, 32, icon.getPixelsPtr());
	


	//background opt
	//-----------------left snake
	sf::Image mainwimg;
	mainwimg.loadFromFile(".//img//snake.png");
	sf::Texture mainwtext;
	mainwtext.loadFromImage(mainwimg);
	sf::Sprite mainwsprt;
	mainwsprt.setTexture(mainwtext);
	mainwsprt.setPosition(730, 550);
	//----------------right snake
	sf::Image mainwimginv;
	mainwimginv.loadFromFile(".//img//snakeinv.png");
	sf::Texture mainwtextinv;
	mainwtextinv.loadFromImage(mainwimginv);
	sf::Sprite mainwsprtinv;
	mainwsprtinv.setTexture(mainwtextinv);
	mainwsprtinv.setPosition(30, 550);


	//String with name of a game
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	sf::Text maintext("|  S N A K E  |", LOGOfont, 140);
	maintext.setStyle(sf::Text::Bold);
	maintext.setFillColor(sf::Color::Black);
	maintext.setPosition(215, 50);

	//start game button----
	Button startgamebtn("->START<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	sf::Font STbtn;
	STbtn.loadFromFile(".//fonts//AGENCYB.TTF");
	startgamebtn.setFont(STbtn);
	startgamebtn.setPosition({ 470, 315 });
	//-----------------OPTION bnt
	Button optionbtn("->OPTIONS<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	optionbtn.setFont(LOGOfont);
	optionbtn.setPosition({ 470, 375 });
	//-----------------ABOUT btn
	Button aboutbtn("->ABOUT<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	aboutbtn.setFont(LOGOfont);
	aboutbtn.setPosition({ 470, 435 });
	//-----------------return btn

	//main loop for window
	while (mainwindow.isOpen()) {
		sf::Event mainev;
		while (mainwindow.pollEvent(mainev)) {
			if (mainev.type == sf::Event::Closed) {
				mainwindow.close();
			}
			if (mainev.type == sf::Event::KeyPressed) {
				if (mainev.key.code == sf::Keyboard::Escape) {
					mainwindow.close();
				}
			}
			if (mainev.type == sf::Event::MouseButtonPressed) {
				if (startgamebtn.isMouseOver(mainwindow)) {
					mainwindow.close();
					new_game_started();
				}
			}
			if (mainev.type == sf::Event::MouseButtonPressed) {
				if (optionbtn.isMouseOver(mainwindow)) {
					mainwindow.close();
					OPTIONS();
				}
			}
			if (mainev.type == sf::Event::MouseButtonPressed) {
				if (aboutbtn.isMouseOver(mainwindow)) {
					mainwindow.close();
					ABOUT();
				}
			}
			mainwindow.clear(DarkGray);

			//draw back
			mainwindow.draw(mainwsprt);
			mainwindow.draw(mainwsprtinv);
			//draw name
			mainwindow.draw(maintext);
			//draw start btn
			startgamebtn.drawTo(mainwindow);
			optionbtn.drawTo(mainwindow);
			aboutbtn.drawTo(mainwindow);
			//draw all screen
			mainwindow.display();
		}
	}
	return 0;
}

int new_game_started() {
	//main game window options
	sf::RenderWindow gswind(sf::VideoMode(1024, 768), "GAME STARTED");
	gswind.setFramerateLimit(60);
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 460, 700 });

	//game window text
	sf::Font gmtxt;
	gmtxt.loadFromFile(".//fonts//AGENCYB.TTF");
	sf::Text sometxt("|  GAME FIELD  |", gmtxt, 35);
	sometxt.setStyle(sf::Text::Underlined);
	sometxt.setFillColor(sf::Color::Black);
	sometxt.setPosition(420, 5);
	
	//game init
	game testgame;
	testgame.setPosition(180, 50);
	snake_matters(testgame.SNAKEMAIN->get_coord()[0], testgame.SNAKEMAIN->get_coord()[1]);

	//main loop for window
	while (gswind.isOpen()) {
		sf::Event gsev;
		while (gswind.pollEvent(gsev)) {
			if (gsev.type == sf::Event::Closed) {
				gswind.close();
			}
			if (gsev.type == sf::Event::KeyPressed) {
				if (gsev.key.code == sf::Keyboard::Escape) {
					gswind.close();
					main_win_gui();
				}
				if (snake_matters(testgame.SNAKEMAIN->get_coord()[0], testgame.SNAKEMAIN->get_coord()[1])) {
					if (gsev.key.code == sf::Keyboard::Left) {
						testgame.SNAKEMAIN->move_to_direction_grow(2, 0);
					}
					if (gsev.key.code == sf::Keyboard::Right) {
						testgame.SNAKEMAIN->move_to_direction_grow(3, 0);
					}
					if (gsev.key.code == sf::Keyboard::Up) {
						testgame.SNAKEMAIN->move_to_direction_grow(1, 0);
					}
					if (gsev.key.code == sf::Keyboard::Down) {
						testgame.SNAKEMAIN->move_to_direction_grow(4, 0);
					}
				}
				else {
					gswind.close();
					main_win_gui();
				}
			}
			if (gsev.type == sf::Event::MouseButtonPressed) {
				if (retbtn.isMouseOver(gswind)) {
					gswind.close();
					main_win_gui();
				}
			}
			gswind.clear(DarkGray);
			gswind.draw(sometxt);
			retbtn.drawTo(gswind);
			gswind.draw(testgame);
			//draw all
			gswind.display();
		}
	}
	return 0;
}

int OPTIONS() {
	//main game window options
	sf::RenderWindow optwind(sf::VideoMode(1024, 768), "OPTIONS");
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 470, 600 });

	//game window text
	sf::Font opttxt;
	opttxt.loadFromFile(".//fonts//AGENCYB.TTF");
	sf::Text sometxt("|  some options here, speed, may be music or sound  |", opttxt, 40);
	sometxt.setStyle(sf::Text::Italic);
	sometxt.setFillColor(sf::Color::Black);
	sometxt.setPosition(200, 50);

	//main loop for window
	while (optwind.isOpen()) {
		sf::Event optev;
		while (optwind.pollEvent(optev)) {
			if (optev.type == sf::Event::Closed) {
				optwind.close();
			}
			if (optev.type == sf::Event::KeyPressed) {
				if (optev.key.code == sf::Keyboard::Escape) {
					optwind.close();
					main_win_gui();
				}
			}
			if (optev.type == sf::Event::MouseButtonPressed) {
				if (retbtn.isMouseOver(optwind)) {
					optwind.close();
					main_win_gui();
					//std::cout << "return to main" << std::endl;
				}
			}
			optwind.clear(DarkGray);
			optwind.draw(sometxt);
			retbtn.drawTo(optwind);
			optwind.display();
		}
	}
	return 0;
}

int ABOUT() {
	//main game window options
	sf::RenderWindow aboutwind(sf::VideoMode(1024, 768), "ABOUT");
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, sf::Color::Black);
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 470, 600 });

	//game window text
	sf::Font abtxt;
	abtxt.loadFromFile(".//fonts//AGENCYB.TTF");
	sf::Text sometxt("|  Some thnx to all  |", abtxt, 50);
	sometxt.setStyle(sf::Text::Italic);
	sometxt.setFillColor(sf::Color::Black);
	sometxt.setPosition(200, 100);

	//main loop for window
	while (aboutwind.isOpen()) {
		sf::Event abev;
		while (aboutwind.pollEvent(abev)) {
			if (abev.type == sf::Event::Closed) {
				aboutwind.close();
			}
			if (abev.type == sf::Event::KeyPressed) {
				if (abev.key.code == sf::Keyboard::Escape) {
					aboutwind.close();
					main_win_gui();
				}
			}
			if (abev.type == sf::Event::MouseButtonPressed) {
				if (retbtn.isMouseOver(aboutwind)) {
					aboutwind.close();
					main_win_gui();
					//std::cout << "return to main" << std::endl;
				}
			}
			aboutwind.clear(DarkGray);
			aboutwind.draw(sometxt);
			retbtn.drawTo(aboutwind);
			aboutwind.display();
		}
	}
	return 0;
}


bool snake_matters(int x, int y) {
	bool live = true;
	if (x >= 65 || y >= 65 || x <= 0 || y <= 0) {
		live = false;
	}
	return live;
}
