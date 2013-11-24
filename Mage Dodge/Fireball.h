#pragma once

#include "BasicFireball.h"
#include "Mage.h"

class Mage;

class Fireball :
	public BasicFireball
{
public:

	Fireball(Mage *player); //constructor
	~Fireball(); //destructor

	void Update(sf::Event &Event); //update

	static int numberOfFb; //total number of fireballs on the screen

private:
	Mage* player; //a pointer to the player
};

