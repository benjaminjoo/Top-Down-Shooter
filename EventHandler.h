#pragma once

#include <SDL/SDL.h>

class EventHandler
{
public:

	SDL_Event event;

	bool quit;
	bool paused;

	EventHandler();
	~EventHandler();

	void HandleUserEvents();
	void ceaseMotion();
};

