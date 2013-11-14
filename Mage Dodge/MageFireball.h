#pragma once

#include "VisualObject.h"
#include "Mage.h"

#define FRAME_WIDTH 32
#define FRAME_HEIGHT 32

#define FRAME_SPEED 500
#define SWITCH_FRAME 100

class MageFireball :
	public VisualObject
{
public:
	MageFireball(Mage::Directions); //constructor
	~MageFireball();//destructor

	void Update(sf::Event &event); //update the object

private:

	Mage::Directions direction; //direction in which the fireball is going

	sf::Vector2i source; //source texture coordinates
	sf::Clock clock; //clock used from frame rate

	float frameCounter;	 //frame variables
};

