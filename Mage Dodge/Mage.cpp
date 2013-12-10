#include "Mage.h"

//constructor
Mage::Mage()
{
	//set the character facing down and standing still
	source.x = 1;
	source.y = Down;

	//making all skills initially available
	CDfireball.setAddTime(29);

	/*MageSkills.Clear();*/

	//setting the frame-rates
	frameCounter = 0;
	frameSpeed = 500;
	switchFrame = 50;

	//HP
	HP = 100;
	//no damage
	Damage = 0;

	//setting clock to 0
	clock.restart();

	//loading the spritesheet into memory
	LoadTexture("GFX\\mage40.png");

	//setting the sprite's texture according to the direction and the phase of movement
	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));

	//set origin of the sprite 
	sprite->setOrigin(sf::Vector2f(FRAME_HEIGHT / 2, FRAME_WIDTH / 2));

	//set position of the sprite
	sprite->setPosition(sf::Vector2f(MAP_WIDTH / 2 + MAP_STARTX, MAP_HEIGHT / 2 + MAP_STARTY));
}

//calling visual object destructor
Mage::~Mage()
{
	std::cout << "mage destructor\n";
}

//updating mage 
void Mage::Update(sf::Event &event)
{

	//increasing the frame counter according to the time elapsed
	frameCounter = frameCounter + (frameSpeed * clock.restart().asSeconds());

	//std::cout << hPoints << std::endl; //debug line

	//if the framecounter became higher than a certain number
	if (frameCounter >= switchFrame)
	{

		frameCounter = 0; //reset the frame counter
		source.x++; //increase the phase of the movement
		if (source.x * FRAME_WIDTH >= texture->getSize().x) //if this is the last phase of the movement
			source.x = 0; //get to the first phase of movement assuring repetition

		//if the up arrow key is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			source.y = Up; //sprite will face up
			sprite->move(0, -5); //move the sprite by 10 pixels
		}
		//if the down arrow key is pressed
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			source.y = Down; //sprite will face down
			sprite->move(0, 5); //move the sprite by 10 pixels
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			source.y = Left; //sprite will face left
			sprite->move(-5, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			source.y = Right; //sprite will face right
			sprite->move(5, 0);
		}

		//if there is no movement
		else
		{
			source.x = 1; //make the sprite stand still
		}

	}

	//if the character is outside the screen automatically put him inside
	if (sprite->getPosition().x - FRAME_WIDTH / 2 < MAP_STARTX)
		sprite->setPosition(sf::Vector2f(MAP_STARTX + FRAME_WIDTH / 2, sprite->getPosition().y));
	else if (sprite->getPosition().x + FRAME_WIDTH / 2 > MAP_WIDTH + MAP_STARTX)
		sprite->setPosition(sf::Vector2f(MAP_WIDTH + MAP_STARTX - FRAME_WIDTH / 2, sprite->getPosition().y));
	else if (sprite->getPosition().y - FRAME_HEIGHT / 2 < MAP_STARTY)
		sprite->setPosition(sf::Vector2f(sprite->getPosition().x, MAP_STARTY + FRAME_HEIGHT / 2));
	else if (sprite->getPosition().y + FRAME_HEIGHT / 2 > MAP_HEIGHT + MAP_STARTY)
		sprite->setPosition(sf::Vector2f(sprite->getPosition().x, MAP_HEIGHT + MAP_STARTY - FRAME_HEIGHT / 2));
	//select the correct texture portion
	sprite->setTextureRect(sf::IntRect(source.x * FRAME_WIDTH, source.y * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));

	LivingObject::Update(event);

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canUseFireball())
	{
		MageFireball *fb = new MageFireball(source.y, sprite->getPosition());
		MageSkills.Insert(fb);
	}*/

	/*MageSkills.CheckVitals();*/

	//MageSkills.UpdateAll(event);

}


void Mage::Draw(sf::RenderWindow &window)
{
	if (sprite != NULL)
		window.draw(*sprite);

	/*MageSkills.DrawAll(window);*/
}

bool Mage::canUseFireball()
{
	if (CDfireball.getTime() >= 30)
	{
		CDfireball.restart();
		return true;
	}

	return false;
}

int Mage::getDirection()
{
	return source.y;
}

sf::Vector2f Mage::getPosition()
{
	return sprite->getPosition();
}