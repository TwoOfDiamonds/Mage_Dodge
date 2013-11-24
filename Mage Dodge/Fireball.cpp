#include "Fireball.h"


int Fireball::numberOfFb = 0;

Fireball::Fireball(Mage *player) :
BasicFireball(BasicFireball::Colors::Red)
{
	//std::cout << "fireball created\n"; //debug line

	dir = (Directions)(rand() % 4); //get a random direction for the fireball to go

	//assign the pointer to the private variable pointer of type Mage
	this->player = player;

	//set the initial position of the fireball depending on the direction it has
	if (dir == Up)
	{
		source.y = Up;
		sprite->setPosition(sf::Vector2f(player->sprite->getPosition().x, MAP_HEIGHT + FRAME_HEIGHT / 2));
	}

	else if (dir == Down)
	{
		source.y = Down;
		sprite->setPosition(sf::Vector2f(player->sprite->getPosition().x, MAP_STARTY - FRAME_HEIGHT / 2));
	}

	else if (dir == Left)
	{
		source.y = Left;
		sprite->setPosition(sf::Vector2f(MAP_WIDTH + FRAME_WIDTH / 2, player->sprite->getPosition().y));
	}
	else if (dir == Right)
	{
		source.y = Right;
		sprite->setPosition(sf::Vector2f(MAP_STARTX - FRAME_WIDTH / 2, player->sprite->getPosition().y));
	}


	//setting the sprite's texture according to the direction and the phase of movement
	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));

	//increase the total number of fireballs
	numberOfFb++;
}

//destructor
Fireball::~Fireball()
{
	//std::cout << "fireball destroyed\n"; //debug line

	//decrease the total number of fireballs
	numberOfFb--;
}

//update
void Fireball::Update(sf::Event &Event)
{
	BasicFireball::Update(Event);

	if (Collide(sprite, player->sprite))
	{
		player->Hit(10);
		Alive = false;
	}

}