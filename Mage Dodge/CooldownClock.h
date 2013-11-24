#pragma once

#include <SFML/Graphics.hpp>

class CooldownClock
{
public:
	CooldownClock();
	~CooldownClock();

	//returns time in seconds
	unsigned int getTime();
	void restart();
	void setAddTime(unsigned int toAdd);

private:
	sf::Clock clock;

	unsigned int startupTime;
};

