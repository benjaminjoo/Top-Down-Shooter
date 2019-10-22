#pragma once

#include <vector>
#include <time.h>

#include "World.h"
#include "Canvas.h"
#include "EventHandler.h"
#include "PlayerVehicle.h"
#include "EnemyVehicle.h"
#include "Projectile.h"
#include "Texture.h"

class Game
{
private:

	clock_t						oldTime;
	clock_t						newTime;
	clock_t						frameTime;
	unsigned int				frameCount;

	std::vector<EnemyVehicle>	Enemies;
	std::vector<Projectile>		Bullets;
	std::vector<Texture>		Textures;

	void updateWorld();
	void updatePlayer();
	void updateEnemies();
	void updateBullets();

	void drawWorld();
	void drawPlayer();
	void drawEnemies();
	void drawBullets();

public:

	World*			Level;
	Canvas*			Screen;
	EventHandler*	Controls;
	PlayerVehicle*	Player;

	unsigned int	nBullet;

	Game(World* L, Canvas* S, EventHandler* E, PlayerVehicle* P);
	~Game();

	void buildBSPTree();

	void addEnemy(EnemyVehicle E);
	void addBullet(Projectile P);
	void addTexture(Texture T);

	void updateAll();
	void drawAll();

	void updateFrameCount();
	void calculateFrametime();

};