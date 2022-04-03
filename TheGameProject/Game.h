#pragma once

#include<iostream>
#include<ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

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