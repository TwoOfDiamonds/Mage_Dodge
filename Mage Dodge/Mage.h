#pragma once

#include "VisualObject.h"
#include "VisualObjectManager.h"
#include "Fireball.h"
#include "MageFireball.h"

#define FRAME_WIDTH 40
#define FRAME_HEIGHT 40

class Mage :
	public VisualObject
{
public:
	enum Directions { Down, Left, Right, Up };

	Mage();
	~Mage();

	void Update(sf::Event &event);

	friend class Fireball;

	void Hit(int dmg);

	void FireFireball();

private:
	//the source portion from the texture
	sf::Vector2i source;
	//animation timer
	//it makes the animation independent from the CPU
	sf::Clock clock;
	
	//container of fireballs
	VisualObjectManager *MageSkills;

	//the current health points of the player
	int hPoints;

	//fireball skill cooldown timer
	sf::Clock CDFireball;

	//animation frame variables
	float frameCounter, frameSpeed, switchFrame;
};

