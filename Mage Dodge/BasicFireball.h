#pragma once

#include "LivingObject.h"
#include <SFML/Graphics.hpp>

#define FRAME_WIDTH 32
#define FRAME_HEIGHT 32

class BasicFireball :
	public LivingObject
{
protected:
	enum Directions { Down, Left, Right, Up }; //enumeration of possible directions
	enum Colors { Red, Pink }; //enumeration of possible colors (according to the function of the fireball)

	BasicFireball(Colors); //constructor with specified color

	virtual void Update(sf::Event &event);

protected:
	Directions dir; //the direction in which the fireball is going
	Colors color; //the color of the fireballs and their role
	
	sf::Vector2i source; //surce texture coordinates
	sf::Clock clock; //frame switch clock

	const float frameSpeed = 500, switchFrame = 37.5f; //frame switch constants
	float frameCounter; //frame counter

	virtual ~BasicFireball(); //destructor

	
};

