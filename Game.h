#pragma once

#include <vector>

#include "World.h"
#include "Canvas.h"
#include "EventHandler.h"
#include "PlayerVehicle.h"
#include "EnemyVehicle.h"
#include "Projectile.h"

class Game
{
private:

	std::vector<EnemyVehicle>	Enemies;
	std::vector<Projectile>		Bullets;

	void updateWorld();
	void updatePlayer();
	void updateEnemies();
	void updateBullets();

	void drawWorld();
	void drawPlayer();
	void drawEnemies();
	void drawBullets();

public:

	World*						Level;
	Canvas*						Screen;
	EventHandler*				Controls;
	PlayerVehicle*				Player;


	Game(World* L, Canvas* S, EventHandler* E, PlayerVehicle* P);
	~Game();

	void addEnemy(EnemyVehicle E);
	void addBullet(Projectile P);

	void updateAll();
	void drawAll();
};

