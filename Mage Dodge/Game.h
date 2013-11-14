#pragma once

#include <SFML/Graphics.hpp>

#include "Splashscreen.h"
#include "Background.h"
#include "VisualObjectManager.h"
#include "FireballManager.h"

class Game
{
public:
	Game();
	~Game();

	//run the game
	void Run();

private:
	//phases of the game
	enum Phase {SplashScreen, Menu, Running, Exit};

	//current phase
	Phase curPhase;

	//state-specific functions
	void GameSplash(sf::Event &event);
	void GameMenu(sf::Event &event);
	void GameRun(sf::Event &event);
	void GameExit(sf::Event &event);

	//initialize all the resources
	void Initialize();

	//initialize the proper game variables
	void GameInit();

	//render window
	sf::RenderWindow window;

	//splash image
	Splashscreen *splash;
	//background game image
	Background *background;
	//mage
	Mage *player;


	//fireball manager
	FireballManager fbManager;
	//object manager
	VisualObjectManager itemManager;

};

