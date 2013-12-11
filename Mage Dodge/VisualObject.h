#pragma once

#define MAP_STARTX 0
#define MAP_STARTY 0
#define MAP_HEIGHT 600
#define MAP_WIDTH 800

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//abstract base class for all objects that are drawn
class VisualObject
{
public:
	VisualObject(); //constructor
	VisualObject(std::string filename); //constructor
	virtual ~VisualObject(); //destructor

	bool LoadTexture(std::string filename); //load texture from path
	void Draw(sf::RenderWindow &window); //draw sprite to window

	virtual void Update(sf::Event &event);

	virtual void Hit(int dmg) = 0;
	virtual int getDmg() = 0;

	bool getAlive();

	virtual void CollisionAction() = 0;

	static bool Collide(VisualObject *vo1, VisualObject *vo2);


protected:
	sf::Texture *texture; //texture
	sf::Sprite *sprite; //sprite

	//check collisions between 2 sprites or 2 visual objects 
	static bool Collide(sf::Sprite *spr1, sf::Sprite *spr2);

	bool Alive;
};
