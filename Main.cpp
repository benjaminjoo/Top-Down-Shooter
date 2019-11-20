#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <memory>

#include <cstdlib>
#include <ctime>


#include "Game.h"
#include "World.h"
#include "Canvas.h"
#include "PlayerVehicle.h"
#include "EnemyVehicle.h"
#include "Projectile.h"
#include "EventHandler.h"
#include "Math.h"
#include "Utilities.h"
#include "Texture.h"
#include "BSPTree.h"
#include "PongBall.h"
#include "PongBar.h"
#include "PongGame.h"
#include "Maze.h"


void physics();
void bspTree();
void pong();
void maze();
void maze(unsigned int w, unsigned int h, unsigned int u, unsigned int t);


int main(int argc, char** argv)
{
	if (argc == 5)
	{
		unsigned int mazeWidth	= unsigned int(atoi(argv[1]));
		unsigned int mazeHeight = unsigned int(atoi(argv[2]));
		unsigned int mazeUnit	= unsigned int(atoi(argv[3]));
		unsigned int mazeThck	= unsigned int(atoi(argv[4]));

		if (mazeWidth > 256)
			mazeWidth = 256;
		if (mazeWidth < 4)
			mazeWidth = 4;
		if (mazeHeight > 256)
			mazeHeight = 256;
		if (mazeHeight < 4)
			mazeHeight = 4;
		if (mazeUnit < 4)
			mazeUnit = 4;
		if (mazeThck >= mazeUnit / 2)
			mazeThck = mazeUnit / 2 - 1;
		if (mazeThck < 1)
			mazeThck = 1;


		std::cout << "Maze Width:		" << mazeWidth << std::endl;
		std::cout << "Maze Height:		" << mazeWidth << std::endl;
		std::cout << "Maze Unit:		" << mazeUnit << std::endl;
		std::cout << "Maze Thickness:	" << mazeThck << std::endl;

		maze(mazeWidth, mazeHeight, mazeUnit, mazeThck);
	}
	else
	{
		maze();
	}

	//pong();
	//physics();
	//bspTree();

	return 0;
}


void maze()
{

#define WIDTH	32
#define HEIGHT	32
#define UNIT	16
#define THCK	2

	auto Screen = std::make_shared<Canvas>(WIDTH * UNIT, HEIGHT * UNIT, 1.0f, "Maze Generation");
	Screen->setClearColour(argbColour(0, 0, 0, 0));

	EventHandler Controls;

	Maze Labyrinth(Screen, WIDTH, HEIGHT, UNIT, THCK);
	Labyrinth.setColour(argbColour(0, 255, 255, 255));

	Screen->clear();

	srand(unsigned int(time(NULL)));

	while (Controls.isRunning())	
	{
		if (!Controls.paused && !Labyrinth.isComplete)
		{
			Labyrinth.construct();
		}
		
		Controls.HandleUserEvents();

		Screen->update();
	}
}


void maze(unsigned int w, unsigned int h, unsigned int u, unsigned int t)
{
	auto Screen = std::make_shared<Canvas>(w * u, h * u, 1.0f, "Maze Generation");
	Screen->setClearColour(argbColour(0, 0, 0, 0));

	EventHandler Controls;

	Maze Labyrinth(Screen, w, h, u, t);
	Labyrinth.setColour(argbColour(0, 255, 255, 255));

	Screen->clear();

	srand(unsigned int(time(NULL)));

	while (Controls.isRunning())
	{
		if (!Controls.paused && !Labyrinth.isComplete)
		{
			Labyrinth.construct();
		}

		Controls.HandleUserEvents();

		Screen->update();
	}
}


void bspTree()
{
	auto Screen = std::make_shared<Canvas>(1024, 600, 0.5f, "BSP Tree Visualisation");
	Screen->setClearColour(argbColour(0, 0, 0, 255));

	EventHandler Controls;

	Tree test_tree(Screen, 40);

	srand(unsigned int(time(NULL)));
	unsigned int n = 20;
	for (unsigned int i = 0; i < n; i++)
	{
		test_tree.add2Tree(rand() % 79 + 1);
	}


	while (Controls.isRunning())
	{
		Screen->clear();

		test_tree.drawTree();

		Controls.HandleUserEvents();

		Screen->update();
	}
}


void physics()
{
	auto Space		= std::make_shared<World>("The Final Frontier");
	auto Screen		= std::make_shared<Canvas>(1200, 600, 0.5f, "Untitled");
	auto Controls	= std::make_shared<EventHandler>(0.0f, 0.0f, 0.0f, 1.0f);
	auto Pilot		= std::make_shared<PlayerVehicle>(60.0f, 80.0f, 100.0f, vect2(500.0f, 500.0f), 0.0f, vect2(1.0f, -1.0f));

	Game Shooter(Space, Screen, Controls, Pilot);

	Shooter.Screen->setClearColour(argbColour(0, 0, 0, 255));

	Shooter.addTexture(Texture("Assets/blue.jpg"));
	Shooter.addTexture(Texture("Assets/millenium_falcon_top_view_small.jpg"));


	Space->addEdge(edge(vect2(140.7, 223.5), vect2(621.0, 223.5)));
	Space->addEdge(edge(vect2(621.0, 223.5), vect2(621.0, 79.2)));
	Space->addEdge(edge(vect2(621.0, 79.2), vect2(1275.4, 79.2)));
	Space->addEdge(edge(vect2(1275.4, 79.2), vect2(1275.4, 365.4)));
	Space->addEdge(edge(vect2(1275.4, 365.4), vect2(1912.4, 365.4)));
	Space->addEdge(edge(vect2(1912.4, 365.4), vect2(1912.4, 153.9)));
	Space->addEdge(edge(vect2(1912.4, 153.9), vect2(2300.6, 153.9)));
	Space->addEdge(edge(vect2(2300.6, 153.9), vect2(2300.6, 945.1)));
	Space->addEdge(edge(vect2(2300.6, 945.1), vect2(1591.4, 945.1)));
	Space->addEdge(edge(vect2(1591.4, 945.1), vect2(1591.4, 1099.4)));
	Space->addEdge(edge(vect2(1591.4, 1099.4), vect2(842.4, 1099.4)));
	Space->addEdge(edge(vect2(842.4, 1099.4), vect2(842.4, 798.3)));
	Space->addEdge(edge(vect2(842.4, 798.3), vect2(66.1, 798.3)));
	Space->addEdge(edge(vect2(66.1, 798.3), vect2(66.1, 467.4)));
	Space->addEdge(edge(vect2(140.7, 467.4), vect2(140.7, 223.5)));
	Space->addEdge(edge(vect2(66.1, 467.4), vect2(140.7, 467.4)));


	srand(unsigned int(time(NULL)));
	unsigned int nBullets = 10;
	for (unsigned int i = 0; i < nBullets; i++)
	{
		vect2 pos;
		pos.x = 600.0 + (double)(rand() % 800);
		pos.y = 400.0 + (double)(rand() % 200);
		double ang = (double)(rand() % 360 / 180.0f * PI);
		double speed = 6.0f;
		vect2 vel(speed * cos(ang), speed * sin(ang));
		Shooter.addBullet(Projectile(Shooter.nBullet, pos, 0.0f, vel, vect2(0.0f, 0.0f), 50.0f));
	}

	Shooter.buildBSPTree();

	while (Shooter.Controls->isRunning())
	{
		Shooter.calculateFrametime();


		Shooter.drawAll();
		Shooter.updateAll();


		Shooter.updateFrameCount();
	}
}


#define PITCH_LENGTH	1200
#define PITCH_HEIGHT	600

void pong()
{
	auto Space		= std::make_shared<World>("Pong");
	auto Screen		= std::make_shared<Canvas>(PITCH_LENGTH, PITCH_HEIGHT, 1.0f, "Pong");
	auto Controls	= std::make_shared<EventHandler>(0.0f, 0.0f, 0.0f, 1.0f);
	auto Ball		= std::make_shared<PongBall>(10.0f);
	auto Player		= std::make_shared<PongBar>();

	PongGame PingPong(Space, Screen, Controls, Ball, Player);

	PingPong.Screen->setClearColour(argbColour(0, 0, 0, 255));

	Space->addEdge(edge(vect2(10.0, 10.0), vect2(1190.0, 10.0)));
	Space->addEdge(edge(vect2(20.0, 590.0), vect2(10.0, 10.0)));
	Space->addEdge(edge(vect2(1190.0, 590.0), vect2(20.0, 590.0)));

	Player->addEdge(edge(vect2(900.0f, -100.0f), vect2(900.0f, 100.0f)));

	//Space.addEdge(edge(vect2(1146.0, 24.0), vect2(817.0, 70.0)));
	//Space.addEdge(edge(vect2(817.0, 70.0), vect2(1146.0, 24.0)));
	//Space.addEdge(edge(vect2(817.0, 70.0), vect2(629.0, 50.0)));
	//Space.addEdge(edge(vect2(629.0, 50.0), vect2(817.0, 70.0)));
	//Space.addEdge(edge(vect2(629.0, 50.0), vect2(546.0, 16.0)));
	//Space.addEdge(edge(vect2(546.0, 16.0), vect2(629.0, 50.0)));
	//Space.addEdge(edge(vect2(546.0, 16.0), vect2(255.0, 20.0)));
	//Space.addEdge(edge(vect2(255.0, 20.0), vect2(546.0, 16.0)));
	//Space.addEdge(edge(vect2(255.0, 20.0), vect2(31.0, 49.0)));
	//Space.addEdge(edge(vect2(31.0, 49.0), vect2(255.0, 20.0)));
	//Space.addEdge(edge(vect2(31.0, 49.0), vect2(17.0, 163.0)));
	//Space.addEdge(edge(vect2(17.0, 163.0), vect2(31.0, 49.0)));
	//Space.addEdge(edge(vect2(17.0, 163.0), vect2(51.0, 346.0)));
	//Space.addEdge(edge(vect2(51.0, 346.0), vect2(17.0, 163.0)));
	//Space.addEdge(edge(vect2(51.0, 346.0), vect2(21.0, 435.0)));
	//Space.addEdge(edge(vect2(21.0, 435.0), vect2(51.0, 346.0)));
	//Space.addEdge(edge(vect2(21.0, 435.0), vect2(129.4, 542.6)));
	//Space.addEdge(edge(vect2(129.4, 542.6), vect2(21.0, 435.0)));
	//Space.addEdge(edge(vect2(129.4, 542.6), vect2(442.6, 491.0)));
	//Space.addEdge(edge(vect2(442.6, 491.0), vect2(129.4, 542.6)));
	//Space.addEdge(edge(vect2(442.6, 491.0), vect2(559.0, 548.6)));
	//Space.addEdge(edge(vect2(559.0, 548.6), vect2(442.6, 491.0)));
	//Space.addEdge(edge(vect2(559.0, 548.6), vect2(843.4, 523.4)));
	//Space.addEdge(edge(vect2(843.4, 523.4), vect2(559.0, 548.6)));
	//Space.addEdge(edge(vect2(843.4, 523.4), vect2(935.8, 462.2)));
	//Space.addEdge(edge(vect2(935.8, 462.2), vect2(843.4, 523.4)));
	//Space.addEdge(edge(vect2(935.8, 462.2), vect2(1153.0, 475.4)));
	//Space.addEdge(edge(vect2(1153.0, 475.4), vect2(935.8, 462.2)));

	//Player.addEdge(edge(vect2(900.0f, -50.0f), vect2(880.0f, 0.0f)));
	//Player.addEdge(edge(vect2(880.0f, 0.0f), vect2(900.0f, 50.0f)));

	while (PingPong.Controls->isRunning())
	{
		PingPong.calculateFrametime();


		PingPong.drawAll();
		PingPong.updateAll();

		vect2 currentPos = Ball->getPosition();

		if (currentPos.x < 0						||
			currentPos.x >= (double)PITCH_LENGTH	||
			currentPos.y < 0						||
			currentPos.y >= (double)PITCH_HEIGHT
			)
		{
			Ball->reset();
		}

		PingPong.updateFrameCount();
	}
}