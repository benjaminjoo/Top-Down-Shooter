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


void physics();
void bspTree();


int main(int argc, char** argv)
{

	//physics();
	bspTree();



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
	World Space("The Final Frontier");
	Canvas Screen(1200, 600, 0.5f, "Untitled");
	EventHandler Controls(0.0f, 0.0f, 0.0f, 1.0f);
	PlayerVehicle Pilot(60.0f, 80.0f, 100.0f, vect2(500.0f, 500.0f), 0.0f, vect2(1.0f, -1.0f));
	Game Shooter(&Space, &Screen, &Controls, &Pilot);


	Shooter.Screen->setClearColour(argbColour(0, 0, 0, 0));

	Shooter.addTexture(Texture("Assets/blue.jpg"));
	Shooter.addTexture(Texture("Assets/millenium_falcon_top_view_small.jpg"));

	//Space.addEdge(edge(vect2(138.0, 510.0),		vect2(20.0, 420.0	)));
	//Space.addEdge(edge(vect2(20.0, 420.0),		vect2(173.0, 201.0	)));
	//Space.addEdge(edge(vect2(173.0, 201.0),		vect2(81.0, 70.0	)));
	//Space.addEdge(edge(vect2(81.0, 70.0),		vect2(202.0, 13.0	)));
	//Space.addEdge(edge(vect2(202.0, 13.0),		vect2(627.0, 130.0	)));
	//Space.addEdge(edge(vect2(627.0, 130.0),		vect2(885.0, 38.0	)));
	//Space.addEdge(edge(vect2(885.0, 38.0),		vect2(1105.0, 83.0	)));
	//Space.addEdge(edge(vect2(1105.0, 83.0),		vect2(1149.0, 341.0	)));
	//Space.addEdge(edge(vect2(1149.0, 341.0),	vect2(1031.0, 416.0	)));
	//Space.addEdge(edge(vect2(1031.0, 416.0),	vect2(944.0, 539.0	)));
	//Space.addEdge(edge(vect2(944.0, 539.0),		vect2(744.0, 453.0	)));
	//Space.addEdge(edge(vect2(744.0, 453.0),		vect2(471.0, 555.0	)));
	//Space.addEdge(edge(vect2(471.0, 555.0),		vect2(299.0, 461.0	)));
	//Space.addEdge(edge(vect2(299.0, 461.0),		vect2(138.0, 510.0	)));


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


	//Space.addEdge(edge(vect2(116.9, 1173.7), vect2(49.8, 889.9)));
	//Space.addEdge(edge(vect2(49.8, 889.9), vect2(220.1, 724.8)));
	//Space.addEdge(edge(vect2(220.1, 724.8), vect2(85.9, 482.3)));
	//Space.addEdge(edge(vect2(85.9, 482.3), vect2(610.0, 259.5)));
	//Space.addEdge(edge(vect2(610.0, 259.5), vect2(566.7, 49.0)));
	//Space.addEdge(edge(vect2(566.7, 49.0), vect2(1198.3, 160.4)));
	//Space.addEdge(edge(vect2(1198.3, 160.4), vect2(1452.1, 98.5)));
	//Space.addEdge(edge(vect2(1452.1, 98.5), vect2(1470.7, 494.8)));
	//Space.addEdge(edge(vect2(1470.7, 494.8), vect2(1706.0, 649.6)));
	//Space.addEdge(edge(vect2(1706.0, 649.6), vect2(1897.9, 420.5)));
	//Space.addEdge(edge(vect2(1897.9, 420.5), vect2(1780.3, 179.0)));
	//Space.addEdge(edge(vect2(1780.3, 179.0), vect2(2294.2, 79.9)));
	//Space.addEdge(edge(vect2(2294.2, 79.9), vect2(2170.4, 618.6)));
	//Space.addEdge(edge(vect2(2170.4, 618.6), vect2(2337.5, 903.4)));
	//Space.addEdge(edge(vect2(2337.5, 903.4), vect2(2176.6, 1126.3)));
	//Space.addEdge(edge(vect2(2176.6, 1126.3), vect2(1371.6, 977.7)));
	//Space.addEdge(edge(vect2(1371.6, 977.7), vect2(1080.6, 1014.9)));
	//Space.addEdge(edge(vect2(1080.6, 1014.9), vect2(1037.3, 1194.4)));
	//Space.addEdge(edge(vect2(1037.3, 1194.4), vect2(702.9, 1101.6)));
	//Space.addEdge(edge(vect2(702.9, 1101.6), vect2(492.4, 959.1)));
	//Space.addEdge(edge(vect2(492.4, 959.1), vect2(116.9, 1173.7)));


	//Space.addEdge(edge(vect2(550.4, 650.4), vect2(624.7, 837.0)));
	//Space.addEdge(edge(vect2(624.7, 837.0), vect2(953.7, 631.2)));
	//Space.addEdge(edge(vect2(550.4, 650.4), vect2(842.8, 553.7)));
	//Space.addEdge(edge(vect2(842.8, 553.7), vect2(953.7, 631.2)));

	//Space.turnInsideOut();

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