#include "LivingObject.h"


LivingObject::LivingObject()
{
}


LivingObject::~LivingObject()
{
}

int LivingObject::getDmg()
{
	return Damage;
}

void LivingObject::Hit(int dmg)
{
	HP -= dmg;
}

void LivingObject::Update(sf::Event &event)
{
	if (HP <= 0)
		Alive = false;
}

void LivingObject::CollisionAction()
{

}