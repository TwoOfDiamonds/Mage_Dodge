#include "VisualObject.h"


//Construct empty object
VisualObject::VisualObject()
{
	texture = NULL;
	sprite = NULL;

	Alive = true;
}


//Construct VisualObject with texture initialization from filename path
VisualObject::VisualObject(std::string filename)
{
	texture = new sf::Texture();

	if (!texture->loadFromFile(filename))
	{
		std::cout << "cannot load file at: " << filename << std::endl;
	}

	else
	{
		texture->setSmooth(true);
	}
		
}


//destructor
VisualObject::~VisualObject()
{
	//std::cout << "object destructed" << std::endl; //debug line

	//if there is a dynamically assigned texture release the memory
	if (texture != NULL)
	{
		delete texture;
		texture = NULL;
	}

	//if there is a dynamically assigned sprite release the memory
	if (sprite != NULL)
	{
		delete sprite;
		sprite = NULL;
	}
}

//load a texture from a specified file path
bool VisualObject::LoadTexture(std::string filename)
{
	texture = new sf::Texture;
	sprite = new sf::Sprite;

	if (!texture->loadFromFile(filename))
	{
		std::cout << "cannot load file at: " << filename << std::endl;
		return false;
	}

	texture->setSmooth(true);
	sprite->setTexture(*texture);

	return true;
}

//draw the sprite on the window
void VisualObject::Draw(sf::RenderWindow &window)
{
	//if there is a sprite loaded draw it on the window
	if (sprite != NULL)
		window.draw(*sprite);
}

void VisualObject::Update(sf::Event &event)
{
}

bool VisualObject::getAlive()
{
	return Alive;
}

bool VisualObject::Collide(sf::Sprite *spr1, sf::Sprite *spr2)
{
	sf::FloatRect rect1(spr1->getPosition().x, spr1->getPosition().y, spr1->getLocalBounds().width, spr1->getLocalBounds().height);
	sf::FloatRect rect2(spr2->getPosition().x, spr2->getPosition().y, spr2->getLocalBounds().width, spr2->getLocalBounds().height);

	return rect1.intersects(rect2);
}