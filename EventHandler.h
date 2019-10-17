#pragma once

#include <SDL/SDL.h>

class EventHandler
{
private:

	bool running;

public:

	SDL_Event event;

	bool paused;

	double turn;
	double move;
	double strafe;

	double sensitivity;

	EventHandler(const double& turn_, const double& move_, const double& strf_, const double& sens_);
	~EventHandler();

	bool isRunning();

	void HandleUserEvents();
	void ceaseMotion();
};

