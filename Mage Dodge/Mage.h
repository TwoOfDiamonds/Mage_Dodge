#pragma once

#include "VisualObject.h"
#include "VisualObjectManager.h"
#include "Fireball.h"
#include "MageFireball.h"
#include "CooldownClock.h"

#define FRAME_WIDTH 40
#define FRAME_HEIGHT 40

class VisualObjectManager;
class CooldownClock;

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

	void Draw(sf::RenderWindow &window);

	int getDirection();
	sf::Vector2f getPosition();

	bool canUseFireball();

private:
	//the source portion from the texture
	sf::Vector2i source;
	//animation timer
	//it makes the animation independent from the CPU
	sf::Clock clock;
	
	//container of fireballs
	//VisualObjectManager MageSkills;

	//the current health points of the player
	int hPoints;


	//animation frame variables
	float frameCounter, frameSpeed, switchFrame;

	//SKILLS WILL BE NOTED LIKE THIS: <element><nameOfTheSkill>

	//when the mage shoots a fireball
	/*void FireFireball();*/
	//fireball cooldown timer
	CooldownClock CDfireball;
};