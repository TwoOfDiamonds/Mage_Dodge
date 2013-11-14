#include "Background.h"


Background::Background()
{
	LoadTexture("GFX//GridBorder.png");
	sprite->setTextureRect(sf::IntRect(0, 0, MAP_WIDTH, MAP_HEIGHT));
	texture->setRepeated(true);
	sprite->setPosition(MAP_STARTX, MAP_STARTY);
}

//destructor
Background::~Background()
{
	std::cout << "background destructed\n";
}
