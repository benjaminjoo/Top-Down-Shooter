#include <iostream>

#include "Game.h"

/*
Game::Game()
{
	Level		= World("level01.txt");
	Screen		= Canvas(1200, 600, 1.0f, "Top Down Shooter");
	Controls	= EventHandler();
	Player		= PlayerVehicle(100.0f, vect2(300.0f, 400.0f), 0.0f, vect2(10.0f, 1.0f));
}
*/

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


void Game::updateWorld()
{
	Level->draw(Screen);
}


void Game::updatePlayer()
{
	Player->update();
}


void Game::updateEnemies()
{
	for (auto i : Enemies)
	{
		i.update();
	}
}


void Game::updateBullets()
{
	for (auto i : Bullets)
	{
		i.update();
	}
}


void Game::drawWorld()
{

}


void Game::drawPlayer()
{
	Player->draw(Screen);
}


void Game::drawEnemies()
{
	for (auto i : Enemies)
	{
		i.draw(Screen);
	}
}


void Game::drawBullets()
{
	for (auto i : Bullets)
	{
		i.draw(Screen);
	}
}


void Game::updateAll()
{
	this->updateWorld();
	this->updatePlayer();
	this->updateEnemies();
	this->updateBullets();
}


void Game::drawAll()
{
	this->updateWorld();
	this->drawPlayer();
	this->drawEnemies();
	this->drawBullets();
	Screen->update();
}
