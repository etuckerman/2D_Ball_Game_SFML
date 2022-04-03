#pragma once

#include<iostream>
#include<ctime>

#include "Player.h"

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	void initVariables();
	void initWindow();

public:
	//constructors and destructors
	Game();
	~Game();

	//accessors

	//modifiers

	//functions
	const bool running() const;
	void pollEvents();

	void update();
	void render();
};