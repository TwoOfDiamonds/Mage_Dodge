#pragma once
#include "VisualObject.h"
class LivingObject :
	public VisualObject
{
public:
	LivingObject();
	virtual ~LivingObject();

protected:
	int HP;
	int Damage;
	virtual void Update(sf::Event &event);
	void Hit(int dmg);
	int getDmg();
	virtual void CollisionAction();
};

