#pragma once

#include <time.h>

#include "World.h"
#include "Canvas.h"
#include "EventHandler.h"
#include "PongBall.h"
#include "PongBar.h"

class PongGame
{
private:
	void updateWorld();
	void updatePlayer();
	void updateBall();

	void drawWorld();
	void drawPlayer();
	void drawBall();

public:

	//World*						Level;
	//Canvas*						Screen;
	//EventHandler*					Controls;
	//PongBall*						Ball;
	//PongBar*						Player;

	std::shared_ptr<World>			Level;
	std::shared_ptr<Canvas>			Screen;
	std::shared_ptr<EventHandler>	Controls;
	std::shared_ptr<PongBall>		Ball;
	std::shared_ptr<PongBar>		Player;

	clock_t			oldTime;
	clock_t			newTime;
	clock_t			frameTime;
	clock_t			frameCount;

	//PongGame(World* L, Canvas* S, EventHandler* C, PongBall* B, PongBar* P);
	PongGame(	std::shared_ptr<World>			L,
				std::shared_ptr<Canvas>			S,
				std::shared_ptr<EventHandler>	C,
				std::shared_ptr<PongBall>		B,
				std::shared_ptr<PongBar>		P);
	~PongGame();

	void updateAll();
	void drawAll();

	void updateFrameCount();
	void calculateFrametime();
};

