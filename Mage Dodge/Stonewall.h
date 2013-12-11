#pragma once
#include "LivingObject.h"

#define SPRITE_HEIGHT 32
#define SPRITE_WIDTH 32

class Stonewall :
	public LivingObject
{
public:
	Stonewall(sf::Vector2f pos);
	~Stonewall();
public:
	void Update(sf::Event &event);
};

