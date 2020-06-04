#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "game.h"
#include <Windows.h>
#include "apple.h"
#include <random>
#include <time.h>
#include <stdlib.h>
#include "random.h"


//fnc observ
int main_win_gui();
int new_game_started();
int OPTIONS();
int ABOUT();
//----------------
//snake options
double speed = 0;
//---------------
//snake move parametrs and speed
int move = 0;
bool appleGOT = 0;
//randomAPPLE
rnd_t randomap;
//---------
//-------
//APPLE
apple MAINAPPLE(rand() % 65, rand() % 65);
//-------

int main_win_gui() {
	
	//--------
	//main window menu options
	sf::RenderWindow mainwindow(sf::VideoMode(1024, 768), "SNAKE");
	//icon
	/*
	sf::Image icon;
	icon.loadFromFile(".//img//icon.png");
	mainwindow.setIcon(80, 80, icon.getPixelsPtr());
	*/
	//---------
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
	maintext.setFillColor(TEXTS);
	maintext.setPosition(215, 50);
	//----------------
	//start game button----
	Button startgamebtn("->START<-", { 105, 55 }, 50, DarkGray, TEXTS);
	sf::Font STbtn;
	STbtn.loadFromFile(".//fonts//AGENCYB.TTF");
	startgamebtn.setFont(STbtn);
	startgamebtn.setPosition({ 470, 315 });
	//-----------------OPTION bnt
	Button optionbtn("->OPTIONS<-", { 105, 55 }, 50, DarkGray, TEXTS);
	optionbtn.setFont(LOGOfont);
	optionbtn.setPosition({ 470, 375 });
	//-----------------ABOUT btn
	Button aboutbtn("->ABOUT<-", { 105, 55 }, 50, DarkGray, TEXTS);
	aboutbtn.setFont(LOGOfont);
	aboutbtn.setPosition({ 470, 435 });
	//-----------------exit btn
	Button exitbtn("->EXIT<-", { 105, 55 }, 50, DarkGray, TEXTS);
	exitbtn.setFont(LOGOfont);
	exitbtn.setPosition({ 470, 495 });

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
				if (optionbtn.isMouseOver(mainwindow)) {
					mainwindow.close();
					OPTIONS();
				}
				if (aboutbtn.isMouseOver(mainwindow)) {
					mainwindow.close();
					ABOUT();
				}
				if (exitbtn.isMouseOver(mainwindow)) {
					mainwindow.close();
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
			exitbtn.drawTo(mainwindow);
			//draw all screen
			mainwindow.display();
		}
	}
	return 0;
}

int new_game_started() {
	//main game window options
	sf::RenderWindow gswind(sf::VideoMode(1024, 768), "GAME STARTED");
	gswind.setFramerateLimit(120);
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, TEXTS);
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 460, 700 });
	//game window text
	sf::Font gmtxt;
	gmtxt.loadFromFile(".//fonts//AGENCYB.TTF");
	sf::Text sometxt("|  GAME FIELD  |", gmtxt, 35);
	sometxt.setStyle(sf::Text::Underlined);
	sometxt.setFillColor(TEXTS);
	sometxt.setPosition(420, 5);
	//LOGO
	//wasted logo (if DIE)
	//-----------1------------
	sf::Image diesnake;
	diesnake.loadFromFile(".//img//wasted.png");
	sf::Texture diestexture;
	diestexture.loadFromImage(diesnake);
	sf::Sprite diesprite;
	diesprite.setTexture(diestexture);
	diesprite.setPosition(265, 150);
	//wasted logo (if win)
	//-----------1------------
	sf::Image winsnake;
	winsnake.loadFromFile(".//img//game_over.png");
	sf::Texture wintexture;
	wintexture.loadFromImage(winsnake);
	sf::Sprite winsprite;
	winsprite.setTexture(wintexture);
	winsprite.setPosition(205, 150);
	//--------------
	//game INIT && init opt
	game testgame;
	testgame.setPosition(180, 50);
	testgame.SNAKEMAIN->set_sn_speed_change(speed);
	sf::Clock snclock;
	//------------------
	//main loop for window
	while (gswind.isOpen()) {
		sf::Event gsev;
		//time to move snake and fnc to check DIE snake
		if (testgame.SNAKEMAIN->snake_dies()) {
			if (snclock.getElapsedTime().asSeconds() >= testgame.SNAKEMAIN->get_sn_speed()) {
				testgame.SNAKEMAIN->move_to_direction_grow(move, appleGOT);
				if (appleGOT) {
					appleGOT = 0;
					MAINAPPLE.set_apple_alive_status(0);
				}
				snclock.restart();
				
			}
			if (!MAINAPPLE.get_apple_alive_status()) {
				MAINAPPLE.set_apple_coord(randomap.irnd(64), randomap.irnd(64));
			}
			if (testgame.SNAKEMAIN->get_length() == 2222) {
				gswind.draw(winsprite);
				move = 0;
				gswind.display();
				while (gswind.pollEvent(gsev)) {
					if (gsev.type == sf::Event::Closed) {
						move = 0;
						gswind.close();
						main_win_gui();
					}
					if (gsev.type == sf::Event::KeyPressed) {
						move = 0;
						gswind.close();
						main_win_gui();
					}
					if (gsev.type == sf::Event::MouseButtonPressed) {
						if (retbtn.isMouseOver(gswind)) {
							move = 0;
							gswind.close();
							main_win_gui();
						}
					}
				}
			}
		}
		else {
			gswind.draw(diesprite);
			move = 0;
			gswind.display();
			while (gswind.pollEvent(gsev)) {
				if (gsev.type == sf::Event::Closed) {
					move = 0;
					gswind.close();
					main_win_gui();
				}
				if (gsev.type == sf::Event::KeyPressed) {
					move = 0;
					gswind.close();
					main_win_gui();
				}
				if (gsev.type == sf::Event::MouseButtonPressed) {
					if (retbtn.isMouseOver(gswind)) {
						move = 0;
						gswind.close();
						main_win_gui();
					}
				}
			}
		}
		while (gswind.pollEvent(gsev)) {
			if (gsev.type == sf::Event::Closed) {
				move = 0;
				gswind.close();
				testgame.SNAKEMAIN->move_to_direction_grow(0, 0);
				testgame.SNAKEMAIN->set_snake_way(0);
				main_win_gui();
			}
			if (gsev.type == sf::Event::KeyPressed) {
				if (gsev.key.code == sf::Keyboard::Escape) {
					move = 0;
					gswind.close();
					testgame.SNAKEMAIN->move_to_direction_grow(0, 0);
					main_win_gui();
				}
				if (gsev.key.code == sf::Keyboard::Left || gsev.key.code == sf::Keyboard::Right || gsev.key.code == sf::Keyboard::Down || gsev.key.code == sf::Keyboard::Up) {
					if (move == 0) {
						if (gsev.key.code == sf::Keyboard::Right) {
							move = 3;
						}
						if (gsev.key.code == sf::Keyboard::Up) {
							move = 1;
						}
						if (gsev.key.code == sf::Keyboard::Down) {
							move = 4;
						}
					}
					if (move == 2) {
						if (gsev.key.code == sf::Keyboard::Left) {
							move = 2;
						}
						if (gsev.key.code == sf::Keyboard::Up) {
							move = 1;
						}
						if (gsev.key.code == sf::Keyboard::Down) {
							move = 4;
						}
					}
					if (move == 3) {
						if (gsev.key.code == sf::Keyboard::Right) {
							move = 3;
						}
						if (gsev.key.code == sf::Keyboard::Up) {
							move = 1;
						}
						if (gsev.key.code == sf::Keyboard::Down) {
							move = 4;
						}
					}
					if (move == 1) {
						if (gsev.key.code == sf::Keyboard::Left) {
							move = 2;
						}
						if (gsev.key.code == sf::Keyboard::Right) {
							move = 3;
						}
						if (gsev.key.code == sf::Keyboard::Up) {
							move = 1;
						}
					}
					if (move == 4) {
						if (gsev.key.code == sf::Keyboard::Left) {
							move = 2;
						}
						if (gsev.key.code == sf::Keyboard::Right) {
							move = 3;
						}
						if (gsev.key.code == sf::Keyboard::Down) {
							move = 4;
						}
					}
				}
			}
			if (gsev.type == sf::Event::MouseButtonPressed) {
				if (retbtn.isMouseOver(gswind)) {
					move = 0;
					gswind.close();
					main_win_gui();
				}
			}
		}
		gswind.clear(DarkGray);
		gswind.draw(sometxt);
		retbtn.drawTo(gswind);
		gswind.draw(testgame);
		//draw all
		gswind.display();
	}
	return 0;
}

int OPTIONS() {
	//main game window options
	sf::RenderWindow optwind(sf::VideoMode(1024, 768), "OPTIONS");
	//main font
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, TEXTS);
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 470, 600 });
	//game opt btn
	//---+
	Button minusbtn("-", { 50, 90 }, 50, DarkGray, TEXTS);
	minusbtn.setFont(LOGOfont);
	minusbtn.setPosition({ 400, 305 });
	//---  -
	Button plusbtn("+", { 50, 50 }, 50, DarkGray, TEXTS);
	plusbtn.setFont(LOGOfont);
	plusbtn.setPosition({ 600, 332 });
	//---ON
	Button ONbtn("ON", { 60, 60 }, 40, DarkGray, TEXTS);
	ONbtn.setFont(LOGOfont);
	ONbtn.setPosition({ 450, 410 });
	//---OFf
	Button OFFbtn("OFF", { 60, 60 }, 40, DarkGray, TEXTS);
	OFFbtn.setFont(LOGOfont);
	OFFbtn.setPosition({ 550, 410 });
	//--------------
	//texts
	//game window text
	sf::Text sometxt("| OPTIONS |", LOGOfont, 80);
	sometxt.setStyle(sf::Text::Underlined);
	sometxt.setFillColor(TEXTS);
	sometxt.setPosition(370, 130);
	//main option speed
	sf::Text sptxt("speed", LOGOfont, 40);
	sptxt.setStyle(sf::Text::Bold);
	sptxt.setFillColor(TEXTS);
	sptxt.setPosition(240, 350);
	//main option speed
	sf::Text darktxt("night mode", LOGOfont, 40);
	darktxt.setStyle(sf::Text::Bold);
	darktxt.setFillColor(TEXTS);
	darktxt.setPosition(240, 420);
	//-----------------
	//------------main loop for window
	while (optwind.isOpen()) {
		sf::Event optev;
		//speedometr
		sf::Text speedtxt(std::to_string(speed), LOGOfont, 30);
		speedtxt.setStyle(sf::Text::Italic);
		speedtxt.setFillColor(TEXTS);
		speedtxt.setPosition(470, 360);
		//--------------------
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
				}
				if (plusbtn.isMouseOver(optwind)) {
					speed -= 0.05;
				}
				if (minusbtn.isMouseOver(optwind)) {
					speed += 0.05;
				}
				if (ONbtn.isMouseOver(optwind)) {
					FillCell.r = 19;
					FillCell.g = 58;
					FillCell.b = 112;
					OutLine.r = 1;
					OutLine.g = 3;
					OutLine.b = 12;
					GameField.r = 110;
					GameField.g = 110;
					GameField.b = 110;
					DarkGray.r = 55;
					DarkGray.g = 7;
					DarkGray.b = 52;
					TEXTS.r = 51;
					TEXTS.g = 51;
					TEXTS.b = 51;

				}
				if (OFFbtn.isMouseOver(optwind)) {
					FillCell.r = 0xDB;
					FillCell.g = 0x70;
					FillCell.b = 0x93;
					OutLine.r = 0xFF;
					OutLine.g = 0x63;
					OutLine.b = 0x47;
					GameField.r = 0x00;
					GameField.g = 0x80;
					GameField.b = 0x80;
					DarkGray.r = 0xA9;
					DarkGray.g = 0xA9;
					DarkGray.b = 0xA9;
					TEXTS.r = 0;
					TEXTS.g = 0;
					TEXTS.b = 0;
				}
			}
		}
		optwind.clear(DarkGray);
		optwind.draw(sptxt);
		optwind.draw(darktxt);
		optwind.draw(sometxt);
		optwind.draw(speedtxt);
		plusbtn.drawTo(optwind);
		minusbtn.drawTo(optwind);
		ONbtn.drawTo(optwind);
		OFFbtn.drawTo(optwind);
		retbtn.drawTo(optwind);
		optwind.display();
	}
	return 0;
}

int ABOUT() {
	//main game window options
	sf::RenderWindow aboutwind(sf::VideoMode(1024, 768), "ABOUT");
	//-----btns
	//-----rtrn btn
	Button retbtn("->RETURN<-", { 105, 55 }, 50, DarkGray, TEXTS);
	sf::Font LOGOfont;
	LOGOfont.loadFromFile(".//fonts//AGENCYB.TTF");
	retbtn.setFont(LOGOfont);
	retbtn.setPosition({ 470, 600 });

	//game window text
	sf::Text sometxt("| ABOUT |", LOGOfont, 60);
	sometxt.setStyle(sf::Text::Underlined);
	sometxt.setFillColor(TEXTS);
	sometxt.setPosition(430, 100);
	//----------------
	//thnx
	sf::Color thnx(sf::Color::Black);
	sf::Text thnxtxt("This is simple SNAKE game on pure C++, with use SFML lib for graphics part.\n For that in my level ill spend about ~30 hourse, nice work as i think.\n So a few THNXis for my friends for help:", LOGOfont, 25);
	thnxtxt.setFillColor(thnx);
	thnxtxt.setStyle(sf::Text::Italic);
	thnxtxt.setPosition(180, 200);
	//main loop for window
	//thnx
	sf::Text namestxt("I. Platov Anton aka.bug - for help with clases logic build and random class\nII. gim(@gim) https://twitter.com/gim?s=03 for help with choose of graphics lib\nIII. Popovich A - For beta testing and fresh mind\nIV. aka.13\n...Game by Poltavskiy Nick aka.Dies_Irae...", LOGOfont, 25);
	namestxt.setFillColor(thnx);
	namestxt.setStyle(sf::Text::Bold);
	namestxt.setPosition(185, 300);
	//main loop for window
	while (aboutwind.isOpen()) {
		if (thnx.r < 255) {
			thnx.r+= 50;
			thnx.g += 50;
			thnx.b += 50;
			thnx.a += 50;

		}
		else {
			thnx.r -= 50;
			thnx.g -= 50;
			thnx.b -= 50;
			thnx.a -= 50;

		}
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
				}
			}
		}
		aboutwind.clear(DarkGray);
		aboutwind.draw(thnxtxt);
		aboutwind.draw(namestxt);
		aboutwind.draw(sometxt);
		retbtn.drawTo(aboutwind);
		aboutwind.display();
	}
	return 0;
}
