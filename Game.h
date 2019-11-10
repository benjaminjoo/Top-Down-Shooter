#pragma once

#include <vector>
#include <memory>
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
	clock_t						frameCount;

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

	std::shared_ptr<World>			Level;
	std::shared_ptr<Canvas>			Screen;
	std::shared_ptr<EventHandler>	Controls;
	std::shared_ptr<PlayerVehicle>	Player;

	unsigned int	nBullet;

	Game(	std::shared_ptr<World>			L,
			std::shared_ptr<Canvas>			S,
			std::shared_ptr<EventHandler>	C,
			std::shared_ptr<PlayerVehicle>	P);
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