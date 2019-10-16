#pragma once

#include <string>
#include <memory>
#include <SDL/SDL.h>
#include "Math.h"

class Canvas
{
private:

	int				width;
	int				height;

	double			scale;

	SDL_Window*		window;
	SDL_Renderer*	screen;
	SDL_Texture*	texture;

	bool			closed;

protected:

	Uint32*			pixelBuffer;
	Uint32			clearColour;

public:
	Canvas(const int& w, const int& h, const double& s, const std::string& title);
	~Canvas();

	void setClearColour(	const unsigned char& a,
							const unsigned char& r,
							const unsigned char& g,
							const unsigned char& b	);

	void clear();
	void update();

	int getWidth();
	int getHeight();

	void drawLine(const screenCoord& startP, const screenCoord& endP, const Uint32& colour);
	void drawBoundingBox(boundingBoxScreen BB, const Uint32& colour);
	void drawCircle(const screenCoord& centreP, const unsigned int& radius, const Uint32& colour);
};

