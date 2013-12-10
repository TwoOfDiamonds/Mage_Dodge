#include "MageFireball.h"


MageFireball::MageFireball(int direction, sf::Vector2f pos) :
BasicFireball(BasicFireball::Colors::Pink)
{
	std::cout << "magefireball constructed" << std::endl; //debug line

	//store the direction at which the casting mage is looking
	dir = (Directions)direction;

	//set Health Points and Damage of the fireballs shot by the mage
	HP = 10;
	Damage = 10;
	
	//set the initial position of the fireball depending on the direction it has
	if (dir == Up)
	{
		source.y = Up;
		sprite->setPosition(sf::Vector2f(pos.x, pos.y - FRAME_HEIGHT / 2 - 10));
	}

	else if (dir == Down)
	{
		source.y = Down;
		sprite->setPosition(sf::Vector2f(pos.x, pos.y + FRAME_HEIGHT / 2 + 10));
	}

	else if (dir == Left)
	{
		source.y = Left;
		sprite->setPosition(sf::Vector2f(pos.x - FRAME_WIDTH / 2 - 10, pos.y));
	}
	else if (dir == Right)
	{
		source.y = Right;
		sprite->setPosition(sf::Vector2f(pos.x + FRAME_WIDTH / 2 + 10, pos.y));
	}

	//setting the sprite's texture according to the direction and the phase of movement
	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));


}


MageFireball::~MageFireball()
{
	std::cout << "m fireball destructed\n"; //debug line
}


void MageFireball::Update(sf::Event &event)
{
	BasicFireball::Update(event);
	LivingObject::Update(event);
	   
	std::cout << sprite->getPosition().x << " " << sprite->getPosition().y << std::endl; //debug line
}