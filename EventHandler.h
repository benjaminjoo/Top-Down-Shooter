#pragma once

#include <SDL/SDL.h>

class EventHandler
{
private:

	bool running;

public:

	SDL_Event event;

	bool paused;
	bool firing;

	bool showStats;

	double turn;
	double move;
	double strafe;

	double step_speed;
	double turn_speed;

	double sensitivity;

	EventHandler();
	EventHandler(const double& turn_, const double& move_, const double& strf_, const double& sens_);
	~EventHandler();

	bool isRunning();

	void HandleUserEvents();
	void ceaseMotion();
};

