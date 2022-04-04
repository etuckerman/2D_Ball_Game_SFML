#pragma once

#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>

#include "Player.h"
#include "Swagball.h"


class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	int points;

	sf::Font font;
	sf::Text guiText;

	std::vector<Swagball> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	void initVariables();
	void initWindow();
	void initFonts();
	void initText();

public:
	//constructors and destructors
	Game();
	~Game();

	//accessors

	//modifiers

	//functions
	const bool running() const;
	void pollEvents();

	void spawnSwagBalls();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};