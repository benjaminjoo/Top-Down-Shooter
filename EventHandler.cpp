#include "EventHandler.h"



EventHandler::EventHandler()
{
	event	= { 0 };

	quit	= false;
	paused	= false;
}


EventHandler::~EventHandler()
{
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
				quit = true;
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
