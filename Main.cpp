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
#include "Bone.h"
#include "LongBone.h"
#include "PelvisBone.h"
#include "Walker.h"
#include "Particle.h"
#include "ParticleSystem.h"


void physics();
void bspTree();
void pong();
void validateMazeParams(unsigned int& w, unsigned int& h, unsigned int& u, unsigned int& t, unsigned int& s, unsigned int& x, unsigned int& y);
void maze();
void maze(unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s, unsigned int x, unsigned int y);
void walkCycle();
void particles();


int main(int argc, char** argv)
{
	//if (argc >= 5)
	//{
	//	unsigned int mazeWidth	= unsigned int(atoi(argv[1]));
	//	unsigned int mazeHeight = unsigned int(atoi(argv[2]));
	//	unsigned int mazeUnit	= unsigned int(atoi(argv[3]));
	//	unsigned int mazeThck	= unsigned int(atoi(argv[4]));
	//	unsigned int mazeDelay	= 0;
	//	unsigned int startX		= 0;
	//	unsigned int startY		= 0;
	//
	//	if (argc >= 6)
	//		mazeDelay = unsigned int(atoi(argv[5]));
	//
	//
	//	if (argc == 8)
	//	{
	//		startX = unsigned int(atoi(argv[6]));
	//		startY = unsigned int(atoi(argv[7]));
	//	}
	//
	//	validateMazeParams(mazeWidth, mazeHeight, mazeUnit, mazeThck, mazeDelay, startX, startY);
	//
	//	std::cout << "Width:		" << mazeWidth	 << std::endl;
	//	std::cout << "Height:		" << mazeHeight  << std::endl;
	//	std::cout << "Unit:		" << mazeUnit	 << std::endl;
	//	std::cout << "Thickness:	" << mazeThck	 << std::endl;
	//	std::cout << "Delay:		" << mazeDelay   << std::endl;
	//
	//	maze(mazeWidth, mazeHeight, mazeUnit, mazeThck, mazeDelay, startX, startY);
	//}
	//else
	//{
	//	maze();
	//}

	//pong();
	//physics();
	//bspTree();
	//walkCycle();
	particles();

	return 0;
}


void particles()
{	
	auto Screen = std::make_shared<Canvas>(1200, 600, 1.0f, "Particle System Test");
	Screen->setClearColour(0x0000000f);

	auto Controls = std::make_shared<EventHandler>(1.0f);

	auto smokeMachine = std::make_shared<ParticleSystem>(vect2(600.0f, 500.0f), vect2(0.0f, -1.0f), 1.0f, 1200, 3);
	smokeMachine->setDispersion(0.01f);
	smokeMachine->activate();
	smokeMachine->setGravity(false);

	while (Controls->isRunning())
	{
		Screen->clear();

		Controls->HandleUserEvents();

		smokeMachine->update(Screen, Controls);

		Controls->ceaseMotion();

		Screen->update();
	}
}


void walkCycle()
{
	auto Screen = std::make_shared<Canvas>(1200, 600, 0.5f, "Walk Cycle Visualisation");
	Screen->setClearColour(argbColour(0, 0, 0, 255));

	EventHandler Controls;

	/**/

	//auto base			= std::make_shared<PelvisBone>("Base");
	//auto l_1			= std::make_shared<LongBone>("L-1", LEFT,	100.0f);
	//auto r_1			= std::make_shared<LongBone>("R-1", RIGHT,	100.0f);
	//base->attachBoneLeft(l_1);
	//base->attachBoneRight(r_1);
	//auto l_2			= std::make_shared<LongBone>("L-2", LEFT,	125.0f);
	//auto r_2			= std::make_shared<LongBone>("R-2", RIGHT,	125.0f);
	//base->attachBoneLeft(l_2);
	//base->attachBoneRight(r_2);
	//auto l_3			= std::make_shared<LongBone>("L-3", LEFT, 150.0f);
	//auto r_3			= std::make_shared<LongBone>("R-3", RIGHT, 150.0f);
	//base->attachBoneLeft(l_3);
	//base->attachBoneRight(r_3);
	//auto l_4			= std::make_shared<LongBone>("L-4", LEFT, 125.0f);
	//auto r_4			= std::make_shared<LongBone>("R-4", RIGHT, 125.0f);
	//base->attachBoneLeft(l_4);
	//base->attachBoneRight(r_4);
	//auto l_5			= std::make_shared<LongBone>("L-5", LEFT, 50.0f);
	//auto r_5			= std::make_shared<LongBone>("R-5", RIGHT, 50.0f);
	//base->attachBoneLeft(l_5);
	//base->attachBoneRight(r_5);

	//auto AtSt			= std::make_shared<Walker>(vect2{ 600.0f, 50.0f }, base);

	//AtSt->addRotationKey(LEFT, 0.000f, {  -15.0f, 150.0f,  60.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.125f, {   15.0f, 170.0f,  75.0f,  75.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.250f, {   45.0f, 190.0f, 120.0f,  90.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.375f, {   30.0f, 175.0f,  75.0f,  75.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.500f, {   15.0f, 150.0f,  60.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.625f, {    0.0f, 130.0f,  45.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.750f, {   -5.0f, 110.0f,  30.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(LEFT, 0.875f, {  -10.0f, 130.0f,  45.0f,  60.0f });//,   0.0f });

	//AtSt->addRotationKey(RIGHT, 0.000f, {  10.0f, 175.0f,  75.0f,  75.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.125f, {   0.0f, 160.0f,  60.0f,  75.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.250f, {  -5.0f, 135.0f,  45.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.375f, { -10.0f, 150.0f,  60.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.500f, { -15.0f, 150.0f,  60.0f,  60.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.625f, {  15.0f, 170.0f,  75.0f,  67.5f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.750f, {  45.0f, 190.0f, 120.0f,  45.0f });//,   0.0f });
	//AtSt->addRotationKey(RIGHT, 0.875f, {  15.0f, 185.0f,  85.0f,  60.0f });//,   0.0f });

	//AtSt->updateSkeleton();

	/**/

	auto pelvis			= std::make_shared<PelvisBone>("Pelvis");

	auto left_femur		= std::make_shared<LongBone>("Left Femur", LEFT, 75.0f);
	auto right_femur	= std::make_shared<LongBone>("Right Femur", RIGHT, 75.0f);

	pelvis->attachBoneLeft(left_femur);
	pelvis->attachBoneRight(right_femur);

	auto left_tibia		= std::make_shared<LongBone>("Left Tibia", LEFT, 60.0f);
	auto right_tibia	= std::make_shared<LongBone>("Right Tibia", RIGHT, 60.0f);

	pelvis->attachBoneLeft(left_tibia);
	pelvis->attachBoneRight(right_tibia);

	auto left_foot		= std::make_shared<LongBone>("Left Foot", LEFT, 20.0f);
	auto right_foot		= std::make_shared<LongBone>("Right Foot", RIGHT, 20.0f);

	pelvis->attachBoneLeft(left_foot);
	pelvis->attachBoneRight(right_foot);

	auto Player = std::make_shared<Walker>(vect2{ 600.0f, 50.0f }, pelvis);

	Player->addRotationKey(LEFT,	0.000f, {  60.0f,  75.0f, -30.0f });
	Player->addRotationKey(LEFT,	0.125f, {  75.0f,  90.0f,   0.0f });
	Player->addRotationKey(LEFT,	0.250f, {  90.0f, 105.0f,   0.0f });
	Player->addRotationKey(LEFT,	0.375f, { 105.0f, 112.5f,   0.0f });
	Player->addRotationKey(LEFT,	0.500f, { 120.0f, 120.0f,  30.0f });
	Player->addRotationKey(LEFT,	0.625f, { 105.0f, 135.0f,  60.0f });
	Player->addRotationKey(LEFT,	0.750f, {  90.0f, 120.0f,  45.0f });
	Player->addRotationKey(LEFT,	0.875f, {  75.0f,  90.0f,  15.0f });

	Player->addRotationKey(RIGHT,	0.000f, { 120.0f, 120.0f,  30.0f });
	Player->addRotationKey(RIGHT,	0.125f, { 105.0f, 135.0f,  60.0f });
	Player->addRotationKey(RIGHT,	0.250f, {  90.0f, 120.0f,  45.0f });
	Player->addRotationKey(RIGHT,	0.375f, {  75.0f,  90.0f,  15.0f });
	Player->addRotationKey(RIGHT,	0.500f, {  60.0f,  75.0f, -30.0f });
	Player->addRotationKey(RIGHT,	0.625f, {  75.0f,  90.0f,   0.0f });
	Player->addRotationKey(RIGHT,	0.750f, {  90.0f, 105.0f,   0.0f });
	Player->addRotationKey(RIGHT,	0.875f, { 105.0f, 112.5f,   0.0f });

	Player->updateSkeleton();

	/**/

	Controls.paused = true;

	while (Controls.isRunning())
	{
		Screen->clear();

		Controls.HandleUserEvents();


		if (!Controls.paused)
			Player->updateSkeleton();
		
		Player->drawSkeleton(Screen);
		
		Player->plotRotation(LEFT, Screen);
		Player->plotCurrentRotation(LEFT, Screen);

		//if (!Controls.paused)
		//	AtSt->updateSkeleton();
		//
		//AtSt->drawSkeleton(Screen);
		//AtSt->plotRotation(LEFT, Screen);
		//AtSt->plotCurrentRotation(LEFT, Screen);


		Screen->update();
	}
}


void validateMazeParams(unsigned int& w, unsigned int& h, unsigned int& u, unsigned int& t, unsigned int& s, unsigned int& x, unsigned int& y)
{
	if (w >		256)
		w =		256;
	if (w <		4)
		w =		4;
	if (h >		256)
		h =		256;
	if (h <		4)
		h =		4;
	if (u <		4)
		u =		4;
	if (t >=	u / 2)
		t =		u / 2 - 1;
	if (t <		1)
		t =		1;
	if (s <		0)
		s =		0;
	if (x <		0)
		x =		0;
	if (x >=	w)
		x =		w - 1;
	if (y <		0)
		y =		0;
	if (y >=	h)
		y =		h - 1;
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

	Maze Labyrinth(Screen, WIDTH, HEIGHT, UNIT, THCK, 0);
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

	Screen->exportPng("screenshot.png");
}


void maze(unsigned int w, unsigned int h, unsigned int u, unsigned int t, unsigned int s, unsigned int x, unsigned int y)
{
	auto Screen = std::make_shared<Canvas>(w * u, h * u, 1.0f, "Maze Generation");
	Screen->setClearColour(argbColour(0, 0, 0, 0));

	EventHandler Controls;

	Maze Labyrinth(Screen, w, h, u, t, s, x, y);
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

	Screen->exportPng("screenshot.png");
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