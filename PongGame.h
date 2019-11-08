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

	World*			Level;
	Canvas*			Screen;
	EventHandler*	Controls;
	PongBall*		Ball;
	PongBar*		Player;

	clock_t			oldTime;
	clock_t			newTime;
	clock_t			frameTime;
	clock_t			frameCount;

	PongGame(World* L, Canvas* S, EventHandler* C, PongBall* B, PongBar* P);
	~PongGame();

	void updateAll();
	void drawAll();

	void updateFrameCount();
	void calculateFrametime();
};

