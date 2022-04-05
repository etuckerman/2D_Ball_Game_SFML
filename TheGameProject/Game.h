#pragma once

#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>

#include "Player.h"
#include "Ball.h"


class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

	std::vector<Ball> balls;
	float spawnTimerMax;
	float spawnTimer;
	int maxBalls;

	void initVariables();
	void initWindow();
	void initFonts();
	void initText();

public:
	//constructors and destructors
	Game();
	~Game();

	//accessors
	const bool& getEndGame() const;

	//modifiers

	//functions
	const bool running() const;
	void pollEvents();

	void spawnBalls();
	const int randBallType() const;
	void updatePlayer();
	void updateCollision();
	void updateGui();

	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};