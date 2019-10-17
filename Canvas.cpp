#include <iostream>

#include "Canvas.h"
#include "Utilities.h"

/*
Canvas::Canvas()
{
	width			= 800;
	height			= 600;

	scale			= 1.0;

	closed			= false;

	clearColour		= 0;

	pixelBuffer		= new Uint32[800 * 600];

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Untitled", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

	screen = SDL_CreateRenderer(window, -1, 0);

	texture = SDL_CreateTexture(screen, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 800, 600);

	SDL_ShowCursor(SDL_DISABLE);
}
*/

Canvas::Canvas(const int& w, const int& h, const double& s, const std::string& title)
{
	width			= w;
	height			= h;

	scale			= s;

	closed			= false;

	clearColour		= 0;

	pixelBuffer		= new Uint32[width * height];

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

	screen = SDL_CreateRenderer(window, -1, 0);

	texture = SDL_CreateTexture(screen, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

	SDL_ShowCursor(SDL_DISABLE);

	std::cout << "Canvas created succesfully..." << std::endl;
}


Canvas::~Canvas()
{
	SDL_DestroyTexture(texture);

	SDL_DestroyRenderer(screen);

	SDL_DestroyWindow(window);

	delete[] pixelBuffer;

	std::cout << "Canvas destroyed succesfully..." << std::endl;
}

/*
void Canvas::setClearColour(	const unsigned char& a,
								const unsigned char& r,
								const unsigned char& g,
								const unsigned char& b)
{
	clearColour = (a << 24) | (r << 16) | (g << 8) | (b << 0);
}
*/

void Canvas::setClearColour(Uint32 col)
{
	clearColour = col;
}


void Canvas::clear()
{
	for (int i = 0; i < width * height; i++) { pixelBuffer[i] = clearColour; }
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


double Canvas::getScale() { return scale; }


void Canvas::drawLine(const screenCoord& startP, const screenCoord& endP, const Uint32& colour)
{
	/*No clipping takes place in this method, if either startP or endP
	are off screen, line is discarded entirely. It is assumed that all
	lines form sides of triangles already clipped to the view frustum*/
	
	/*Check if line endpoints differ, and if so, see how much they do*/
	bool diffX = (endP.x - startP.x == 0) ? false : true;
	bool diffY = (endP.y - startP.y == 0) ? false : true;
	int deltaX = endP.x - startP.x;
	int deltaY = endP.y - startP.y;

	int x1, y1, x2, y2;

	if (!diffX && !diffY)
	{
		/*No extent - draw single pixel*/
		int xCurrent = startP.x;
		int yCurrent = startP.y;
		if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
		{
			pixelBuffer[yCurrent * width + xCurrent] = colour;
		}
	}
	if (!diffX && diffY)
	{
		/*No 'X' extent - draw vertical columns of pixels*/
		if (startP.y < endP.y)
		{
			x1 = startP.x;	y1 = startP.y;
			x2 = endP.x;	y2 = endP.y;
		}
		else
		{
			x1 = endP.x;	y1 = endP.y;
			x2 = startP.x;	y2 = startP.y;
		}
		for (int xCurrent = x1, yCurrent = y1; yCurrent < y2; yCurrent++)
		{
			if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
			{
				pixelBuffer[yCurrent * width + xCurrent] = colour;
			}
		}
	}
	if (!diffY && diffX)
	{
		/*No 'Y' extent - draw horizontal row of pixels*/
		if (startP.x < endP.x)
		{
			x1 = startP.x;	y1 = startP.y;
			x2 = endP.x;	y2 = endP.y;
		}
		else
		{
			x1 = endP.x;	y1 = endP.y;
			x2 = startP.x;	y2 = startP.y;
		}
		for (int xCurrent = x1, yCurrent = y1; xCurrent < x2; xCurrent++)
		{
			if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
			{
				pixelBuffer[yCurrent * width + xCurrent] = colour;
			}
		}
	}
	if (diffX && diffY)
	{
		/*Line extends both in the 'X' and 'Y' directions*/
		if (abs(deltaX) == abs(deltaY))
		{
			/*Line extends equally in both directions*/
			int stepY = 0;
			if (startP.x < endP.x)
			{
				x1 = startP.x;	y1 = startP.y;
				x2 = endP.x;	y2 = endP.y;
				stepY = (startP.y < endP.y) ? 1 : -1;
			}
			else
			{
				x1 = endP.x;	y1 = endP.y;
				x2 = startP.x;	y2 = startP.y;
				stepY = (startP.y < endP.y) ? -1 : 1;
			}
			for (int xCurrent = x1, yCurrent = y1; xCurrent < x2; xCurrent++, yCurrent += stepY)
			{
				if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
				{
					pixelBuffer[yCurrent * width + xCurrent] = colour;
				}
			}
		}
		else
		{
			/*Generic line*/
			if (abs(deltaX) >= abs(deltaY))
			{
				/*Line is 'X'-major*/
				int stepY = 0, xCount = 0, yCount = 0;
				if (startP.x < endP.x)
				{
					x1 = startP.x;	y1 = startP.y;
					x2 = endP.x;	y2 = endP.y;
					stepY = (startP.y < endP.y) ? 1 : -1;
				}
				else
				{
					x1 = endP.x;	y1 = endP.y;
					x2 = startP.x;	y2 = startP.y;
					stepY = (startP.y < endP.y) ? -1 : 1;
				}
				for (int xCurrent = x1; xCurrent < x2; xCurrent++, xCount++)
				{
					int yCurrent = y1 + yCount;
					if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
					{
						pixelBuffer[yCurrent * width + xCurrent] = colour;
					}
					float yIdeal = ((float)deltaY / (float)deltaX) * xCount;
					if (abs(yIdeal - yCount) > 0.5f) { yCount += stepY; }
				}
			}
			else
			{
				/*Line is 'Y'-major*/
				int stepX = 0, xCount = 0, yCount = 0;
				if (startP.y < endP.y)
				{
					x1 = startP.x;	y1 = startP.y;
					x2 = endP.x;	y2 = endP.y;
					stepX = (startP.x < endP.x) ? 1 : -1;
				}
				else
				{
					x1 = endP.x;	y1 = endP.y;
					x2 = startP.x;	y2 = startP.y;
					stepX = (startP.x < endP.x) ? -1 : 1;
				}
				for (int yCurrent = y1; yCurrent < y2; yCurrent++, yCount++)
				{
					int xCurrent = x1 + xCount;
					if ((xCurrent >= 0 && xCurrent < width) && (yCurrent >= 0 && yCurrent < height))
					{
						pixelBuffer[yCurrent * width + xCurrent] = colour;
					}
					float xIdeal = ((float)deltaX / (float)deltaY) * yCount;
					if (abs(xIdeal - xCount) > 0.5f) { xCount += stepX; }
				}
			}
		}
	}
}


void Canvas::drawBoundingBox(boundingBoxScreen BB, const Uint32& colour)
{
	BB.clipToScreen(width, height);

	this->drawLine(BB.topLeft, screenCoord(BB.bottomRight.x, BB.topLeft.y), 255);

	this->drawLine(screenCoord(BB.topLeft.x, BB.bottomRight.y), BB.bottomRight, 255);

	this->drawLine(BB.topLeft, screenCoord(BB.topLeft.x, BB.bottomRight.y), 255);

	this->drawLine(screenCoord(BB.bottomRight.x, BB.topLeft.y), BB.bottomRight, 255);
}


void Canvas::drawCircle(const screenCoord& centreP, const int& radius, const Uint32& colour)
{
	boundingBoxScreen bb(centreP.x - radius, centreP.y - radius, centreP.x + radius, centreP.y + radius);
	bb.clipToScreen(width, height);

	for (int j = bb.topLeft.y; j <= bb.bottomRight.y; j++)
	{
		for (int i = bb.topLeft.x; i <= bb.bottomRight.x; i++)
		{
			int pos = (i - centreP.x) * (i - centreP.x) + (j - centreP.y) * (j - centreP.y);
			int brightness = 255 - (int)((double)pos / ((double)radius * (double)radius) * 255);
			if (pos <= (radius * radius))
			{
				pixelBuffer[j * width + i] = argbColour(0, brightness, brightness, 255);
			}
		}
	}
}
