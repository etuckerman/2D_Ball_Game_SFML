#include "Swagball.h"

void Swagball::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));

	sf::Color color;
	switch (this->type)
	{
	case DEFAULT:
			color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
			break;
	case DAMAGING:
			color = sf::Color::Red;
			this->shape.setOutlineColor(sf::Color::Magenta);
			this->shape.setOutlineThickness(2.f);
			break;
	case HEALING:
			color = sf::Color::Green;
			this->shape.setOutlineColor(sf::Color::Yellow);
			this->shape.setOutlineThickness(2.f);
			break;
	}

	this->shape.setFillColor(color);
	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
			static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
		)
	);
}

Swagball::Swagball(const sf::RenderWindow& window, int type)
	: type(type)  //initializer
{
	this->initShape(window);
}

Swagball::~Swagball()
{

}

const sf::CircleShape Swagball::getShape() const
{
	return this->shape;
}

const int & Swagball::getType() const
{
	return this->type;
}

void Swagball::update()
{

}

void Swagball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
