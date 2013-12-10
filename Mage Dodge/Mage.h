#pragma once

#include "LivingObject.h"
#include "VisualObjectManager.h"
#include "Fireball.h"
#include "MageFireball.h"
#include "CooldownClock.h"

#define FRAME_WIDTH 40
#define FRAME_HEIGHT 40

class VisualObjectManager;
class CooldownClock;

class Mage :
	public LivingObject
{
public:
	enum Directions { Down, Left, Right, Up };

	Mage();
	~Mage();

	void Update(sf::Event &event);

	friend class Fireball;

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

	//animation frame variables
	float frameCounter, frameSpeed, switchFrame;

	//SKILLS WILL BE NOTED LIKE THIS: <element><nameOfTheSkill>

	//when the mage shoots a fireball
	/*void FireFireball();*/
	//fireball cooldown timer
	CooldownClock CDfireball;
};