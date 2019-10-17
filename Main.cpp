#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

#include "Game.h"
#include "World.h"
#include "Canvas.h"
#include "PlayerVehicle.h"
#include "EnemyVehicle.h"
#include "Projectile.h"
#include "EventHandler.h"
#include "Math.h"
#include "Utilities.h"


int main(int argc, char** argv)
{

	World Space("The Final Frontier");
	Canvas Screen(1200, 600, 1.0f, "Untitled");
	EventHandler Controls(0.0f, 0.0f, 0.0f, 1.0f);
	PlayerVehicle Pilot(100.0f, vect2(300.0f, 400.0f), 0.0f, vect2(1.0f, -1.0f));
	Game Shooter(&Space, &Screen, &Controls, &Pilot);


	Shooter.Screen->setClearColour(argbColour(0, 0, 0, 255));


	edge* edgePtr = &edge(vect2(100.0f, 500.0f), vect2(900.0f, 400.0f));
	edgePtr->flip();
	Space.addEdge(*edgePtr);
	Space.addEdge(edge(vect2(900.0f, 100.0f), vect2(1150.0f, 300.0f)));

	Shooter.addBullet(Projectile(vect2(200.0f, 200.0f), 0.0f, vect2(2.0f, 1.0f), vect2(0.0f, 0.0f), 10.0f));
	Shooter.addBullet(Projectile(vect2(800.0f, 300.0f), 0.0f, vect2(-1.0f, 0.5f), vect2(0.0f, 0.0f), 10.0f));

	while (Shooter.Controls->isRunning())
	{
		
	

		Shooter.updateAll();
		Shooter.drawAll();


	}


	return 0;
}