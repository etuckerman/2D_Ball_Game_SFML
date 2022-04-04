#include "Swagball.h"

void Swagball::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color color(rand()%255 + 1, rand( )% 255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
			static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
		)
	);
}

Swagball::Swagball(const sf::RenderWindow& window)
{
	this->initShape(window);
}

Swagball::~Swagball()
{
}

void Swagball::update()
{

}

void Swagball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
