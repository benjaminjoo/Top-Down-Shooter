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


int main(int argc, char** argv)
{

	World Space("The Final Frontier");
	Canvas Screen(1200, 600, 0.5f, "Untitled");
	EventHandler Controls(0.0f, 0.0f, 0.0f, 1.0f);
	PlayerVehicle Pilot(120.0f, 160.0f, 100.0f, vect2(300.0f, 400.0f), 0.0f, vect2(1.0f, -1.0f));
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


	Space.addEdge(edge(vect2(116.9, 1173.7), vect2(49.8, 889.9)));
	Space.addEdge(edge(vect2(49.8, 889.9), vect2(220.1, 724.8)));
	Space.addEdge(edge(vect2(220.1, 724.8), vect2(85.9, 482.3)));
	Space.addEdge(edge(vect2(85.9, 482.3), vect2(610.0, 259.5)));
	Space.addEdge(edge(vect2(610.0, 259.5), vect2(566.7, 49.0)));
	Space.addEdge(edge(vect2(566.7, 49.0), vect2(1198.3, 160.4)));
	Space.addEdge(edge(vect2(1198.3, 160.4), vect2(1452.1, 98.5)));
	Space.addEdge(edge(vect2(1452.1, 98.5), vect2(1470.7, 494.8)));
	Space.addEdge(edge(vect2(1470.7, 494.8), vect2(1706.0, 649.6)));
	Space.addEdge(edge(vect2(1706.0, 649.6), vect2(1897.9, 420.5)));
	Space.addEdge(edge(vect2(1897.9, 420.5), vect2(1780.3, 179.0)));
	Space.addEdge(edge(vect2(1780.3, 179.0), vect2(2294.2, 79.9)));
	Space.addEdge(edge(vect2(2294.2, 79.9), vect2(2170.4, 618.6)));
	Space.addEdge(edge(vect2(2170.4, 618.6), vect2(2337.5, 903.4)));
	Space.addEdge(edge(vect2(2337.5, 903.4), vect2(2176.6, 1126.3)));
	Space.addEdge(edge(vect2(2176.6, 1126.3), vect2(1371.6, 977.7)));
	Space.addEdge(edge(vect2(1371.6, 977.7), vect2(1080.6, 1014.9)));
	Space.addEdge(edge(vect2(1080.6, 1014.9), vect2(1037.3, 1194.4)));
	Space.addEdge(edge(vect2(1037.3, 1194.4), vect2(702.9, 1101.6)));
	Space.addEdge(edge(vect2(702.9, 1101.6), vect2(492.4, 959.1)));
	Space.addEdge(edge(vect2(492.4, 959.1), vect2(116.9, 1173.7)));



	//srand(time(NULL));
	//unsigned int nBullets = 10;
	//for (unsigned int i = 0; i < nBullets; i++)
	//{
	//	vect2 pos;
	//	pos.x = 200.0 + (double)(rand() % 800);
	//	pos.y = 200.0 + (double)(rand() % 200);
	//	double ang = (double)(rand() % 360 / 180.0f * PI);
	//	vect2 vel(2.5f * cos(ang), 2.5f * sin(ang));
	//	Shooter.addBullet(Projectile(pos, 0.0f, vel, vect2(0.0f, 0.0f), 25.0f));
	//}

	Shooter.buildBSPTree();

	while (Shooter.Controls->isRunning())
	{
		
	

		Shooter.updateAll();
		Shooter.drawAll();

		

	}



	return 0;
}