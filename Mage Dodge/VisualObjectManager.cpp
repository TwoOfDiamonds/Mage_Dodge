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


void VisualObjectManager::Insert(VisualObject *vo, int index)
{
	sprites.insert(sprites.begin() + index, vo);
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
			++it;
		}
	}
}

void VisualObjectManager::CollideAll(VisualObjectManager *vom, VisualObjectManager *second)
{
	for (auto &it : vom->sprites)
	{
		for (auto &it2 : second->sprites)
		{
			if (VisualObject::Collide(it, it2))
			{
				//std::cout << "they should hit !!!" << std::endl; //debug line
				it2->Hit(it->getDmg());
				it->Hit(it2->getDmg());
			}
		}
	}
}