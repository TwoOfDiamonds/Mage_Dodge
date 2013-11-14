#include "Splashscreen.h"


Splashscreen::Splashscreen()
{
	LoadTexture("GFX//splashscreen.png");
	sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getLocalBounds().height / 2);
	sprite->setPosition((MAP_WIDTH + MAP_STARTX) / 2, (MAP_HEIGHT + MAP_STARTY) / 2);

	std::cout << "splash loaded\n";
}


Splashscreen::~Splashscreen()
{
}