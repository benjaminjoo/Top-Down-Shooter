#include <iostream>

#include "EventHandler.h"



EventHandler::EventHandler(const double& turn_, const double& move_, const double& strf_, const double& sens_)
{
	running			= true;

	event			= { 0 };

	paused			= false;
	firing			= false;

	turn			= turn_;
	move			= move_;
	strafe			= strf_;

	step_speed		= 1.0f;
	turn_speed		= 2.5f;

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
	const Uint8* state = SDL_GetKeyboardState(nullptr);

	if (state[SDL_SCANCODE_UP] && !state[SDL_SCANCODE_DOWN])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			move = step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			move = step_speed * 4;
		}
		else
		{
			move = step_speed;
		}
	}

	if (state[SDL_SCANCODE_DOWN] && !state[SDL_SCANCODE_UP])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			move = -step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			move = -step_speed * 4;
		}
		else
		{
			move = -step_speed;
		}
	}

	if (state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT])
	{
		if (state[SDL_SCANCODE_LALT])
		{
			if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
			{
				strafe = -step_speed * 8;
			}
			else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			{
				strafe = -step_speed * 4;
			}
			else
			{
				strafe = -step_speed;
			}
		}
		else
		{
			turn -= turn_speed;
		}
	}

	if (state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT])
	{
		if (state[SDL_SCANCODE_LALT])
		{
			if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
			{
				strafe = +step_speed * 8;
			}
			else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
			{
				strafe = +step_speed * 4;
			}
			else
			{
				strafe = +step_speed;
			}
		}
		else
		{
			turn += turn_speed;
		}
	}

	if (state[SDL_SCANCODE_W] && !state[SDL_SCANCODE_S])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			move = step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			move = step_speed * 4;
		}
		else
		{
			move = step_speed;
		}
	}

	if (state[SDL_SCANCODE_S] && !state[SDL_SCANCODE_W])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			move = -step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			move = -step_speed * 4;
		}
		else
		{
			move = -step_speed;
		}
	}

	if (state[SDL_SCANCODE_A] && !state[SDL_SCANCODE_D])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			strafe = -step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			strafe = -step_speed * 4;
		}
		else
		{
			strafe = -step_speed;
		}
	}

	if (state[SDL_SCANCODE_D] && !state[SDL_SCANCODE_A])
	{
		if ((state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]) && state[SDL_SCANCODE_SPACE])
		{
			strafe = step_speed * 8;
		}
		else if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT])
		{
			strafe = step_speed * 4;
		}
		else
		{
			strafe = step_speed;
		}
	}


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


	if (event.type == SDL_MOUSEMOTION)
	{
		turn = (double)event.motion.x * sensitivity;
	}

	if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_PRESSED)
	{
		firing = true;
	}

	if (event.button.button == SDL_BUTTON_LEFT && event.button.state == SDL_RELEASED)
	{
		firing = false;
	}
}


void EventHandler::ceaseMotion()
{
	move	= 0.0f;
	strafe	= 0.0f;	
}
