#include "Mouse.h"


Mouse::Mouse()
{
	LoadTexture("GFX//Hand.png");
	sprite->setTextureRect(sf::IntRect(0, 0, 60, 60));
	texture->setRepeated(false);
	sprite->setPosition(sf::Vector2f(MAP_WIDTH / 2, MAP_HEIGHT / 2));
}

Mouse::~Mouse()
{
}

void Mouse::Update(sf::Event &event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		std::cout << "mouse at " << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
		sprite->setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
	}
}