#pragma once

#include<iostream>
#include<ctime>

#include "Player.h"
#include "Swagball.h"
#include<vector>

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	std::vector<Swagball> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

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

	void spawnSwagBalls();
	void update();
	void render();
};