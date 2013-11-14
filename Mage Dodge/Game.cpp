#include "Game.h"


Game::Game()
{
	std::cout << "game const\n";

	//init the resources
	Initialize();
}


Game::~Game()
{
}

//the game loop
void Game::Run()
{
	while (window.isOpen())
	{
		sf::Event Event;

		switch (curPhase)
		{
		case Game::SplashScreen:
			GameSplash(Event);
			break;
		case Game::Menu:
			break;
		case Game::Running:
			GameRun(Event);
			break;
		case Game::Exit:
			itemManager.Clear();
			window.close();
			break;
		default:
			break;
		}


		//see if there is any object that needs deleted
		itemManager.CheckVitals();
		//update all existing objects
		itemManager.UpdateAll(Event);

		//clear the window
		window.clear();

		//draw all existing objects
		if (window.isOpen())
			itemManager.DrawAll(window);
		//draw the buffer
		window.display();
	}
}


//initializing all the resources
void Game::Initialize()
{
	//creating the window
	window.create(sf::VideoMode(800, 600, 32), "Mage Dodge", sf::Style::Titlebar);

	//create a new splashscreen
	splash = new Splashscreen();

	//put the splashscreen into the item manager
	itemManager.Insert(splash);

	//set the current phase of the game to splash screen
	curPhase = Game::SplashScreen;
}


//actions to be considered when the game
//is in splashscreen phase
void Game::GameSplash(sf::Event &Event)
{
	while (window.pollEvent(Event))
	{
		std::cout << "gamesplash\n";

		//at any key press close the splashscreen
		if (Event.type == sf::Event::KeyPressed)
		{
			//delete the splash from item manager
			itemManager.Clear();

			//initialize the game
			GameInit();

			//get to the next phase of the game (MainMenu)
			curPhase = Game::Running;
		}
	}
}

void Game::GameInit()
{
	//create new background and mage
	background = new Background();
	player = new Mage();

	//insert them into item manager
	itemManager.Insert(background);
	itemManager.Insert(player);
}

//handling 1player game
void Game::GameRun(sf::Event &Event)
{
	while (window.pollEvent(Event))
	{
		switch (Event.key.code)
		{
		case sf::Keyboard::Escape:
			itemManager.Clear();
			curPhase = Game::Exit;
		default:
			break;
		}
	}

	if (fbManager.Maintain())
	{
		std::cout << "maintain true\n";
		Fireball *fb = new Fireball(player);
		itemManager.Insert(fb);
	}
}
