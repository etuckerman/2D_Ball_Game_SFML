#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Swagball
{
private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
public:
	Swagball(const sf::RenderWindow& window);
	virtual ~Swagball();

	//functions
	void update();
	void render(sf::RenderTarget& target);
};

