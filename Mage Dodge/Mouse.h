#pragma once
#include "DeadObject.h"
class Mouse :
	public DeadObject
{
public:
	Mouse();
	~Mouse();

private:
	sf::Vector2f mousePosition;
	void Update(sf::Event &event);
};

