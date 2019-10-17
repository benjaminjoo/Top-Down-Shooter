#include <iostream>

#include "EventHandler.h"



EventHandler::EventHandler(const double& turn_, const double& move_, const double& strf_, const double& sens_)
{
	running			= true;

	event			= { 0 };

	paused			= false;

	turn			= turn_;
	move			= move_;
	strafe			= strf_;

	sensitivity		= sens_;

	std::cout << "EventHandler created sussecfully..." << std::endl;
}


EventHandler::~EventHandler()
{
	std::cout << "EventHandler created sussecfully..." << std::endl;
}


bool EventHandler::isRunning()
{
	return running;
}


void EventHandler::HandleUserEvents()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				running = false;
				break;
			default:
				break;
			}
		}
	}
}


void EventHandler::ceaseMotion()
{

}
