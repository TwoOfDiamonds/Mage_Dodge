#include "BasicFireball.h"


BasicFireball::BasicFireball(Colors cl)
{
	color = cl; //set to the selected color

	Alive = true; //set to alive


	//load the correct texture according to the function of the object
	if (color == Colors::Red)
		LoadTexture("GFX//FireBall.png");
	else if (color == Colors::Pink)
		LoadTexture("GFX//mageFB.png");
	
	clock.restart(); // initialize clock

	frameCounter = 0; //init the frame counter
	
	sprite->setOrigin(sf::Vector2f(FRAME_WIDTH / 2, FRAME_HEIGHT / 2)); //set origin of the sprite
}

BasicFireball::~BasicFireball()
{
}

void BasicFireball::Update(sf::Event &event)
{
	//increasing the frame counter according to the time elapsed
	frameCounter = frameCounter + (frameSpeed * clock.restart().asSeconds());

	//if the framecounter became higher than a certain number
	if (frameCounter >= switchFrame)
	{

		frameCounter = 0; //reset the frame counter
		source.x++; //increase the phase of the movement
		if (source.x * FRAME_WIDTH >= texture->getSize().x) //if this is the last phase of the movement
			source.x = 0; //get to the first phase of movement assuring repetition

		//move the fireball depending on the direction
		if (dir == Down)
		{
			sprite->move(0, 7.5f);
		}

		else if (dir == Up)
		{
			sprite->move(0, -7.5f);
		}

		else if (dir == Left)
		{
			sprite->move(-7.5f, 0);
		}

		else if (dir == Right)
		{
			sprite->move(7.5f, 0);
		}

		//system("cls"); //debug line
		//std::cout << "X: " << sprite->getPosition().x << "  Y: " << sprite->getPosition().y << std::endl; //debug line

		if (sprite->getPosition().x + FRAME_WIDTH / 2 < MAP_STARTX - 10 ||
			sprite->getPosition().x - FRAME_WIDTH / 2 > MAP_STARTX + MAP_WIDTH + 10 ||
			sprite->getPosition().y + FRAME_HEIGHT / 2 < MAP_STARTY - 10 ||
			sprite->getPosition().y - FRAME_HEIGHT / 2 > MAP_STARTY + MAP_HEIGHT + 10)
		{
			Alive = false;
		}

		sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT)); //set sprite rectangle from the texture
	}
}