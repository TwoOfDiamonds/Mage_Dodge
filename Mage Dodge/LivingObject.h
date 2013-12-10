#pragma once
#include "VisualObject.h"
class LivingObject :
	public VisualObject
{
public:
	LivingObject();
	virtual ~LivingObject();

	void Hit(int dmg);
	int getDmg();
protected:
	int HP;
	int Damage;
	virtual void Update(sf::Event &event);
};

