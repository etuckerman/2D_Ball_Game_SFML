#include "Swagball.h"

void Swagball::initShape()
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color color(rand()%255 + 1, rand( )% 255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(color);
}

Swagball::Swagball()
{
	this->initShape();
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
