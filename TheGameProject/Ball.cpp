#include "Ball.h"

void Ball::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));

	sf::Color color;
	switch (this->type)
	{
	case DEFAULT:
			color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
			break;
	case DAMAGING:
			color = sf::Color::Black;
			this->shape.setOutlineColor(sf::Color::Red);
			this->shape.setOutlineThickness(2.f);
			break;
	case HEALING:
			color = sf::Color::White;
			this->shape.setOutlineColor(sf::Color::Green);
			this->shape.setOutlineThickness(5.f);
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

Ball::Ball(const sf::RenderWindow& window, int type)
	: type(type)  //initializer
{
	this->initShape(window);
}

Ball::~Ball()
{

}

const sf::CircleShape Ball::getShape() const
{
	return this->shape;
}

const int & Ball::getType() const
{
	return this->type;
}

void Ball::update()
{

}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
