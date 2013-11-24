#include "FireballManager.h"


FireballManager::FireballManager()
{
	frameCount = 0.f;
	clock.restart();
}


FireballManager::~FireballManager()
{
}

bool FireballManager::Maintain()
{
	frameCount += FRAME_SPEED * clock.restart().asSeconds();

	if (frameCount >= FRAME_SWITCH)
	{
		frameCount = 0;
		if (Fireball::numberOfFb < MAX_FBS)
		{
			std::cout << Fireball::numberOfFb << std::endl;
			return true;
		}
	}

	return false;
}