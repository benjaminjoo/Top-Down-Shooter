#include <iostream>

#include "Game.h"


Game::Game(		std::shared_ptr<World>			L,
				std::shared_ptr<Canvas>			S,
				std::shared_ptr<EventHandler>	C,
				std::shared_ptr<PlayerVehicle>	P)
{
	Level		= L;
	Screen		= S;
	Controls	= C;
	Player		= P;

	oldTime		= 0;
	newTime		= 0;
	frameTime	= 0;
	frameCount	= 0;

	nBullet = 0;

	std::cout << "Game created sussecfully..." << std::endl;
}


Game::~Game()
{
	std::cout << "Game created sussecfully..." << std::endl;
}


void Game::buildBSPTree()
{
	polygon rootPoly;

	double w = (double)Screen->getWidth() / Screen->getScale();
	double h = (double)Screen->getHeight() / Screen->getScale();

	rootPoly.n				= 4;
	rootPoly.vertices[0]	= vect2(0.0f, 0.0f);
	rootPoly.vertices[1]	= vect2(w, 0.0f);
	rootPoly.vertices[2]	= vect2(w, h);
	rootPoly.vertices[3]	= vect2(0.0f, h);
	rootPoly.colour			= 0;
	rootPoly.leftChild		= nullptr;
	rootPoly.rightChild		= nullptr;

	Screen->buildPolyTree(&rootPoly, Level->edgeList);
}


void Game::addEnemy(EnemyVehicle E)
{
	Enemies.push_back(E);
}


void Game::addBullet(Projectile P)
{
	Bullets.push_back(P);
	nBullet++;
}


void Game::addTexture(Texture T)
{
	Textures.push_back(T);
}


void Game::updateWorld()
{
	Level->update();
}


void Game::updatePlayer()
{
	Player->update(Controls, Bullets);
	Player->handleCollision(Controls, Level->edgeList);
}


void Game::updateEnemies()
{
	for (auto i = Enemies.begin(); i != Enemies.end(); ++i)
	{
		i->update();
	}
}


void Game::updateBullets()
{
	for (auto i = Bullets.begin(); i != Bullets.end(); ++i)
	{
		i->update(Level->edgeList, Bullets, Screen);
	}
}


void Game::drawWorld()
{
	Level->draw(Screen);
}


void Game::drawPlayer()
{
	Player->draw(Screen);
}


void Game::drawEnemies()
{
	for (auto i = Enemies.begin(); i != Enemies.end(); ++i)
	{
		i->draw(Screen);
	}
}


void Game::drawBullets()
{
	for (auto i = Bullets.begin(); i != Bullets.end(); ++i)
	{
		i->draw(Screen);
	}
}


void Game::updateAll()
{
	Controls->HandleUserEvents();
	if (!Controls->paused)
	{
		this->updateWorld();
		this->updatePlayer();
		this->updateEnemies();
		this->updateBullets();
	}	
	Controls->ceaseMotion();
}


void Game::drawAll()
{
	Screen->clear();
	Screen->drawPolyTree();
	this->drawWorld();
	this->drawPlayer();
	this->drawEnemies();
	this->drawBullets();
	if (Controls->showStats) { Screen->displayValue((double)(30000.0 / frameTime), 1, 10, 10, 255); }
	Screen->update();
}


void Game::updateFrameCount()
{
	frameCount++;
}


void Game::calculateFrametime()
{
	if (frameCount == 30)
	{
		oldTime = newTime;
		newTime = clock();
		frameTime = newTime - oldTime;
		frameCount = 0;
	}
}
