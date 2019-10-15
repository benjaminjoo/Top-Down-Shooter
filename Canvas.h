#pragma once

#include <string>
#include <memory>
#include <SDL/SDL.h>

class Canvas
{
private:

	int				width;
	int				height;

	SDL_Window*		window;
	SDL_Renderer*	screen;
	SDL_Texture*	texture;

	bool			closed;

protected:

	Uint32*			pixelBuffer;

public:
	Canvas(const int& w, const int& h, const std::string& title);
	~Canvas();

	void clear();
	void update();

	int getWidth();
	int getHeight();
};

