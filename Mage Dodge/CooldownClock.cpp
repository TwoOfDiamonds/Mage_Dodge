#include "CooldownClock.h"


CooldownClock::CooldownClock()
{
	startupTime = 0;
	clock.restart();
}


CooldownClock::~CooldownClock()
{
}

void CooldownClock::setAddTime(unsigned int toAdd)
{
	startupTime += toAdd;
}

unsigned int CooldownClock::getTime()
{
	unsigned int toRet = clock.getElapsedTime().asSeconds() + startupTime;

	return toRet;
}

void CooldownClock::restart()
{
	startupTime = 0;
	clock.restart();
}
