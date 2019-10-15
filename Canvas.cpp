#include "Canvas.h"



Canvas::Canvas(const int& w, const int& h, const std::string& title)
{
	width	= w;
	height	= h;

	closed	= false;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

	screen = SDL_CreateRenderer(window, -1, 0);

	texture = SDL_CreateTexture(screen, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

	SDL_ShowCursor(SDL_DISABLE);

	pixelBuffer = new Uint32[width * height];
	
}


Canvas::~Canvas()
{
	SDL_DestroyTexture(texture);

	SDL_DestroyRenderer(screen);

	SDL_DestroyWindow(window);

	delete[] pixelBuffer;
}


void Canvas::clear()
{
	memset(pixelBuffer, 64, width * height * sizeof(Uint32));
}


void Canvas::update()
{
	SDL_UpdateTexture(texture, nullptr, pixelBuffer, width * sizeof(Uint32));

	SDL_RenderClear(screen);

	SDL_RenderCopy(screen, texture, nullptr, nullptr);

	SDL_RenderPresent(screen);
}


int Canvas::getWidth() { return width; }


int Canvas::getHeight() { return height; }
