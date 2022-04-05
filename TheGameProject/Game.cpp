#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;
}

void Game::initWindow()
{
	this->videomode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videomode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "! ERROR::GAME::INITFONT::COULD NOT LOAD PixellettersFull" << "\n";
	}

}

void Game::initText()
{
	//text Gui init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);
}

//constructors and destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}


//functions  


const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::spawnSwagBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;

	else 
	{
		if (this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(Swagball(*this->window, rand()%SwagBallTypes::NROFTYPES)); //randomize the types

			this->spawnTimer = 0.f;
		}
		
	}
}

void Game::updateCollision()
{
	//check collisions
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				this->points++;
				break;
			case SwagBallTypes::DAMAGING:
				this->player.takeDamage(1);
				break;
			case SwagBallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			}
			//remove the ball
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}
}

void Game::updateGui()
{
	std::stringstream ss;

	ss << " - Points: " << this->points << "\n"
		<< " - Health: " << this->player.getHp() << " / " << this->player.getHpMax() << "\n";

	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();

	this->spawnSwagBalls();
	this->player.update(this->window);
	this->updateCollision();
	this->updateGui();

}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();

	//render stuff
	this->player.render(this->window);

	for (auto i : this->swagBalls)
	{
		i.render(*this->window);
	}

	//render gui
	this->renderGui(this->window);

	this->window->display();
}

//functions
