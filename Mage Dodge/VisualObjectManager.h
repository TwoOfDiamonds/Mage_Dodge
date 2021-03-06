#pragma once

#include <vector>
#include <string>

#include "VisualObject.h"
#include "Mage.h"

class VisualObjectManager
{
public:
	VisualObjectManager(); //constructor
	~VisualObjectManager(); //

	//insert visualobject into the sprites map (key, item to be added)
	void Insert(VisualObject *item);
	void Insert(VisualObject *item, int index); //insert at a certain position

	//delete a single visualobject from the sprites map (by key)
	void Remove(int index);
	//delete all items from sprites map
	void Clear();

	void DrawAll(sf::RenderWindow &window); //draw all images from sprites map

	void UpdateAll(sf::Event &event); //update all items

	//check which objects should exist
	//delete those that shouldn't
	//return to see if there is still a point in playing the game (e.g. the player died)
	void CheckVitals();

	static void CollideAll(VisualObjectManager *vom, VisualObjectManager *vomSecond);

private:
	std::vector<VisualObject*> sprites;
};
