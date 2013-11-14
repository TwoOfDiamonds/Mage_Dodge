#include "Fireball.h"


int Fireball::numberOfFb = 0;

Fireball::Fireball(Mage *player)
{
	std::cout << "fireball created\n";

	dir = (Directions)(rand() % 4); //get a random direction for the fireball to go

	//assign the pointer to the private variable pointer of type Mage
	this->player = player;

	//the object was just created so it should exist
	Alive = true;
	
	//set the character facing down and standing still
	source.x = 1;
	source.y = Down;

	//setting the frame-rates
	frameCounter = 0;
	frameSpeed = 500;
	switchFrame = 37.5f;

	//setting clock to 0
	clock.restart();

	//load texture and sprite
	LoadTexture("GFX\\FireBall.png");

	//setting the sprite's texture according to the direction and the phase of movement
	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));

	//set origin of the sprite 
	sprite->setOrigin(sf::Vector2f(FRAME_HEIGHT / 2, FRAME_WIDTH / 2));

	//set the initial position of the fireball depending on the direction it has
	if (dir == Up)
	{
		source.y = Up;
		sprite->setPosition(sf::Vector2f(player->sprite->getPosition().x, MAP_HEIGHT + FRAME_HEIGHT));
	}

	else if (dir == Down)
	{
		source.y = Down;
		sprite->setPosition(sf::Vector2f(player->sprite->getPosition().x, MAP_STARTY - FRAME_HEIGHT));
	}

	else if (dir == Left)
	{
		source.y = Left;
		sprite->setPosition(sf::Vector2f(MAP_WIDTH + FRAME_WIDTH, player->sprite->getPosition().y));
	}
	else if (dir == Right)
	{
		source.y = Right;
		sprite->setPosition(sf::Vector2f(MAP_STARTX - FRAME_WIDTH, player->sprite->getPosition().y));
	}

	//increase the total number of fireballs
	numberOfFb++;
}

//destructor
Fireball::~Fireball()
{
	std::cout << "fireball destroyed\n";

	//decrease the total number of fireballs
	numberOfFb--;
}

//update
void Fireball::Update(sf::Event &Event)
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

		if (Collide(sprite, player->sprite))
		{
			player->Hit(10);
			Alive = false;
		}


	}



	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT)); //set sprite rectangle from the texture

}