#pragma once

#include <vector>

#include "Fireball.h"

#define MAX_FBS 15

#define FRAME_SPEED 500
#define FRAME_SWITCH 100

class FireballManager
{
public:
	FireballManager();
	~FireballManager();

	bool Maintain();

private:
	float frameCount;

	sf::Clock clock;
};

