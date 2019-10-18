#include <iostream>

#include "Game.h"


Game::Game(World* L, Canvas* S, EventHandler* E, PlayerVehicle* P)
{
	Level		= L;
	Screen		= S;
	Controls	= E;
	Player		= P;

	std::cout << "Game created sussecfully..." << std::endl;
}


Game::~Game()
{
	std::cout << "Game created sussecfully..." << std::endl;
}


void Game::addEnemy(EnemyVehicle E)
{
	Enemies.push_back(E);
}


void Game::addBullet(Projectile P)
{
	Bullets.push_back(P);
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
		i->update();
		i->checkForCollision(Level->edgeList, Screen);
	}
}


void Game::drawWorld()
{
	Level->draw(Screen);
}


void Game::drawPlayer()
{
	Player->draw(Screen, &Textures[Player->getTextureID()]);
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
	this->updateWorld();
	this->updatePlayer();
	this->updateEnemies();
	this->updateBullets();
	Controls->ceaseMotion();
}


void Game::drawAll()
{
	Screen->clear();
	this->drawWorld();
	this->drawPlayer();
	this->drawEnemies();
	this->drawBullets();
	Screen->update();
}
