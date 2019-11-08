#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

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


void physics();
void bspTree();
void pong();


int main(int argc, char** argv)
{

	pong();
	//physics();
	//bspTree();



	return 0;
}


void bspTree()
{
	Canvas Screen(1024, 600, 0.5f, "BSP Tree Visualisation");
	Screen.setClearColour(argbColour(0, 0, 0, 255));

	EventHandler Controls;

	//Tree test_tree(&Screen, 10);
	//
	//test_tree.add2Tree(20);
	//test_tree.add2Tree(25);
	//test_tree.add2Tree(5);
	//test_tree.add2Tree(15);
	//test_tree.add2Tree(30);
	//test_tree.add2Tree(40);
	//test_tree.add2Tree(18);
	//test_tree.add2Tree(14);
	//test_tree.add2Tree(8);
	//test_tree.add2Tree(2);

	Tree test_tree(&Screen, 40);

	srand(time(NULL));
	unsigned int n = 20;
	for (unsigned int i = 0; i < n; i++)
	{
		test_tree.add2Tree(rand() % 79 + 1);
	}


	while (Controls.isRunning())
	{
		Screen.clear();

		test_tree.drawTree();

		Controls.HandleUserEvents();

		Screen.update();
	}
}


void physics()
{
	World			Space("The Final Frontier");
	Canvas			Screen(1200, 600, 0.5f, "Untitled");
	EventHandler	Controls(0.0f, 0.0f, 0.0f, 1.0f);
	PlayerVehicle	Pilot(60.0f, 80.0f, 100.0f, vect2(500.0f, 500.0f), 0.0f, vect2(1.0f, -1.0f));

	Game Shooter(&Space, &Screen, &Controls, &Pilot);


	Shooter.Screen->setClearColour(argbColour(0, 0, 0, 0));

	Shooter.addTexture(Texture("Assets/blue.jpg"));
	Shooter.addTexture(Texture("Assets/millenium_falcon_top_view_small.jpg"));


	Space.addEdge(edge(vect2(140.7, 223.5), vect2(621.0, 223.5)));
	Space.addEdge(edge(vect2(621.0, 223.5), vect2(621.0, 79.2)));
	Space.addEdge(edge(vect2(621.0, 79.2), vect2(1275.4, 79.2)));
	Space.addEdge(edge(vect2(1275.4, 79.2), vect2(1275.4, 365.4)));
	Space.addEdge(edge(vect2(1275.4, 365.4), vect2(1912.4, 365.4)));
	Space.addEdge(edge(vect2(1912.4, 365.4), vect2(1912.4, 153.9)));
	Space.addEdge(edge(vect2(1912.4, 153.9), vect2(2300.6, 153.9)));
	Space.addEdge(edge(vect2(2300.6, 153.9), vect2(2300.6, 945.1)));
	Space.addEdge(edge(vect2(2300.6, 945.1), vect2(1591.4, 945.1)));
	Space.addEdge(edge(vect2(1591.4, 945.1), vect2(1591.4, 1099.4)));
	Space.addEdge(edge(vect2(1591.4, 1099.4), vect2(842.4, 1099.4)));
	Space.addEdge(edge(vect2(842.4, 1099.4), vect2(842.4, 798.3)));
	Space.addEdge(edge(vect2(842.4, 798.3), vect2(66.1, 798.3)));
	Space.addEdge(edge(vect2(66.1, 798.3), vect2(66.1, 467.4)));
	Space.addEdge(edge(vect2(140.7, 467.4), vect2(140.7, 223.5)));
	Space.addEdge(edge(vect2(66.1, 467.4), vect2(140.7, 467.4)));


	srand(time(NULL));
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
	World			Space("Pong");
	Canvas			Screen(PITCH_LENGTH, PITCH_HEIGHT, 1.0f, "Pong");
	EventHandler	Controls(0.0f, 0.0f, 0.0f, 1.0f);
	PongBall		Ball;
	PongBar			Player;

	PongGame PingPong(&Space, &Screen, &Controls, &Ball, &Player);

	PingPong.Screen->setClearColour(argbColour(0, 0, 0, 0));

	//Space.addEdge(edge(vect2(10.0, 20.0), vect2(1190.0, 10.0)));
	//Space.addEdge(edge(vect2(10.0, 580.0), vect2(10.0, 20.0)));
	//Space.addEdge(edge(vect2(1190.0, 590.0), vect2(10.0, 580.0)));


	Space.addEdge(edge(vect2(1146.0, 24.0), vect2(817.0, 70.0)));
	Space.addEdge(edge(vect2(817.0, 70.0), vect2(1146.0, 24.0)));
	Space.addEdge(edge(vect2(817.0, 70.0), vect2(629.0, 50.0)));
	Space.addEdge(edge(vect2(629.0, 50.0), vect2(817.0, 70.0)));
	Space.addEdge(edge(vect2(629.0, 50.0), vect2(546.0, 16.0)));
	Space.addEdge(edge(vect2(546.0, 16.0), vect2(629.0, 50.0)));
	Space.addEdge(edge(vect2(546.0, 16.0), vect2(255.0, 20.0)));
	Space.addEdge(edge(vect2(255.0, 20.0), vect2(546.0, 16.0)));
	Space.addEdge(edge(vect2(255.0, 20.0), vect2(31.0, 49.0)));
	Space.addEdge(edge(vect2(31.0, 49.0), vect2(255.0, 20.0)));
	Space.addEdge(edge(vect2(31.0, 49.0), vect2(17.0, 163.0)));
	Space.addEdge(edge(vect2(17.0, 163.0), vect2(31.0, 49.0)));
	Space.addEdge(edge(vect2(17.0, 163.0), vect2(51.0, 346.0)));
	Space.addEdge(edge(vect2(51.0, 346.0), vect2(17.0, 163.0)));
	Space.addEdge(edge(vect2(51.0, 346.0), vect2(21.0, 435.0)));
	Space.addEdge(edge(vect2(21.0, 435.0), vect2(51.0, 346.0)));
	Space.addEdge(edge(vect2(21.0, 435.0), vect2(129.4, 542.6)));
	Space.addEdge(edge(vect2(129.4, 542.6), vect2(21.0, 435.0)));
	Space.addEdge(edge(vect2(129.4, 542.6), vect2(442.6, 491.0)));
	Space.addEdge(edge(vect2(442.6, 491.0), vect2(129.4, 542.6)));
	Space.addEdge(edge(vect2(442.6, 491.0), vect2(559.0, 548.6)));
	Space.addEdge(edge(vect2(559.0, 548.6), vect2(442.6, 491.0)));
	Space.addEdge(edge(vect2(559.0, 548.6), vect2(843.4, 523.4)));
	Space.addEdge(edge(vect2(843.4, 523.4), vect2(559.0, 548.6)));
	Space.addEdge(edge(vect2(843.4, 523.4), vect2(935.8, 462.2)));
	Space.addEdge(edge(vect2(935.8, 462.2), vect2(843.4, 523.4)));
	Space.addEdge(edge(vect2(935.8, 462.2), vect2(1153.0, 475.4)));
	Space.addEdge(edge(vect2(1153.0, 475.4), vect2(935.8, 462.2)));



	Player.addEdge(edge(vect2(900.0f, -50.0f), vect2(880.0f, 0.0f)));
	Player.addEdge(edge(vect2(880.0f, 0.0f), vect2(900.0f, 50.0f)));

	while (PingPong.Controls->isRunning())
	{
		PingPong.calculateFrametime();


		PingPong.drawAll();
		PingPong.updateAll();

		vect2 currentPos = Ball.getPosition();

		if (currentPos.x < 0						||
			currentPos.x >= (double)PITCH_LENGTH	||
			currentPos.y < 0						||
			currentPos.y >= (double)PITCH_HEIGHT
			)
		{
			Ball.reset();
		}

		PingPong.updateFrameCount();
	}
}