#pragma once

#include "VisualObject.h"
#include "Mage.h"

#define FRAME_WIDTH 32
#define FRAME_HEIGHT 32

class Mage;

class Fireball :
	public VisualObject
{
public:
	enum Directions { Down, Left, Right, Up }; //enumeration of possible directions

	Fireball(Mage *player); //constructor
	~Fireball(); //destructor

	void Update(sf::Event &Event); //update

	static int numberOfFb; //total number of fireballs on the screen

private:
	Directions dir; //in which direction is the fireball going

	sf::Vector2i source; //source texture coordinates
 	sf::Clock clock; //clock used from frame rate

	float frameCounter, frameSpeed, switchFrame; //frame variables

	Mage* player; //a pointer to the player
};

