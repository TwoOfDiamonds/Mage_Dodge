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

	bool getAlive();

protected:
	sf::Texture *texture; //texture
	sf::Sprite *sprite; //sprite

	bool Collide(sf::Sprite *spr1, sf::Sprite *spr2);

	bool Alive;
};
