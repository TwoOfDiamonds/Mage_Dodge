#include "Stonewall.h"


Stonewall::Stonewall(sf::Vector2f pos)
{
	Alive = true; //the object is initially alive
	HP = 30; //it can stand 3 hits
	Damage = 0; //it doesn't deal any damage

	LoadTexture("GFX//stone_dark.png");

	sprite->setOrigin(sf::Vector2f(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2)); //set the coords of space in the center

	sprite->setPosition(pos);
}


Stonewall::~Stonewall()
{
}

void Stonewall::Update(sf::Event &event)
{
	LivingObject::Update(event);
}
