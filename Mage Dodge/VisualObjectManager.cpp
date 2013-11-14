#include "VisualObjectManager.h"

//empty constructor
VisualObjectManager::VisualObjectManager()
{
}

//empty destructor
VisualObjectManager::~VisualObjectManager()
{
	Clear();
}

//insert a pair of <string, VisualObject> into the sprites map
void VisualObjectManager::Insert(VisualObject *item)
{
	sprites.push_back(item);
}

//delete an item found by string key from the sprites map
void VisualObjectManager::Remove(int index)
{
	delete sprites[index];

	sprites.erase(sprites.begin() + index);
	
}

//delete all the items from the sprites map
void VisualObjectManager::Clear()
{
	for (auto& it : sprites)
	{
		delete it;
	}

	sprites.clear();
}

//draw all the items from the sprites map to the window
void VisualObjectManager::DrawAll(sf::RenderWindow &window)
{
	for (auto& it : sprites)
	{
		it->Draw(window);
	}
}

void VisualObjectManager::UpdateAll(sf::Event &event)
{
	for (auto& it : sprites)
	{
		it->Update(event);
	}
}

void VisualObjectManager::CheckVitals()
{
	for (std::vector<VisualObject*>::iterator it = sprites.begin(); it != sprites.end();)
	{
		if ((*it)->getAlive() == false)
		{
			delete *it;
			it = sprites.erase(it);
		}

		else
		{
			it++;
		}
	}
}