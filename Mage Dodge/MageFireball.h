#pragma once

#include "BasicFireball.h"
#include "Mage.h"

class MageFireball :
	public BasicFireball
{
public:
	MageFireball(int dir, sf::Vector2f pos); //constructor
	~MageFireball();//destructor

	void Update(sf::Event &event); //update the object
};

