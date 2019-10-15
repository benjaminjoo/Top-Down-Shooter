#pragma once

#include <SDL/SDL.h>

class EventHandler
{
public:

	SDL_Event event;

	bool quit;
	bool paused;

	double turn;
	double move;
	double strafe;

	double sensitivity;

	EventHandler();
	~EventHandler();

	void HandleUserEvents();
	void ceaseMotion();
};

