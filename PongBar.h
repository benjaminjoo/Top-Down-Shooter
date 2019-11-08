#pragma once

#include <vector>
#include <SDL/SDL.h>
#include <string>
#include "Math.h"
#include "Utilities.h"
#include "Canvas.h"


class PongBar
{
private:
	vect2				position;
	Uint32				colour;

public:
	std::vector<edge>	edgeList;

	PongBar();
	~PongBar();

	void addEdge(edge e);
	void update(vect2 translation);
	void draw(Canvas* screen);
};

