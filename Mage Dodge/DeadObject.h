#pragma once
#include "VisualObject.h"
class DeadObject :
	public VisualObject
{
public:
	DeadObject();
	virtual ~DeadObject();
protected:
	void Hit(int dmg);
	int getDmg();
	void CollisionAction();
protected:
	//virtual void Update(sf::Event &event);
};

