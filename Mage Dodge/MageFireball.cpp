#include "MageFireball.h"


MageFireball::MageFireball(Mage::Directions dir)
{
	LoadTexture("GFX//MagicFireball.png");
	direction = dir;

	sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getLocalBounds().height / 2);
}


MageFireball::~MageFireball()
{
}
